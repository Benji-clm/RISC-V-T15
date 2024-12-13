module branch_pred #(
    parameter ADDRESS_WIDTH = 32,
    parameter BHT_ENTRIES   = 64,            // Number of BHT entries
    parameter BHT_INDEX_BITS = 6             // log2(BHT_ENTRIES)
)(
    input  logic                     clk,
    input  logic                     reset,

    // Inputs for prediction (fetch stage)
    input  logic [ADDRESS_WIDTH-1:0] pcF,

    // Inputs for branch resolution (execute stage)
    input  logic [ADDRESS_WIDTH-1:0] pcE,
    input  logic                     branch_valid,   // Indicates that the instruction at pcE was a branch
    input  logic                     branch_taken,    // Actual outcome of the branch
    input  logic [ADDRESS_WIDTH-1:0] targetE,         // Actual target of the branch

    // Outputs for prediction
    output logic                     branch_predictF,
    output logic [ADDRESS_WIDTH-1:0] branch_targetF
);

    // Two-bit saturating counters
    // 00: strongly not taken
    // 01: weakly not taken
    // 10: weakly taken
    // 11: strongly taken
    typedef logic [1:0] bht_state_t;

    // Branch History Table
    // Indexed by some subset of PC bits.
    bht_state_t bht [0:BHT_ENTRIES-1];

    // Branch Target Buffer
    // Stores the target address for predicted-taken branches.
    logic [ADDRESS_WIDTH-1:0] btb [0:BHT_ENTRIES-1];

    // Compute the index into the BHT and BTB using PC
    // Typically use lower bits of PC since instructions are aligned by 4 bytes.
    wire [BHT_INDEX_BITS-1:0] indexF = pcF[BHT_INDEX_BITS+1:2];
    wire [BHT_INDEX_BITS-1:0] indexE = pcE[BHT_INDEX_BITS+1:2];

    // Prediction at fetch
    bht_state_t stateF;
    always_comb begin
        stateF = bht[indexF];
        // Predict taken if state is '10' or '11'
        if (stateF[1] == 1) begin
            branch_predictF = 1'b1;
            branch_targetF = btb[indexF];
        end else begin
            branch_predictF = 1'b0;
            branch_targetF = pcF + 4;
        end
    end

    // Update the BHT and BTB at the execute stage when branch outcome is known
    always_ff @(negedge clk) begin
        if (reset) begin
            integer i;
            for (i = 0; i < BHT_ENTRIES; i++) begin
                bht[i] <= 2'b00; // initialize all to strongly not taken
                btb[i] <= '0;
            end
        end else begin
            if (branch_valid) begin
                bht_state_t current_state = bht[indexE];
                // Update saturating counter based on actual outcome
                if (branch_taken) begin
                    // Taken: increment state up to 11
                    case (current_state)
                        2'b00: bht[indexE] <= 2'b01; // strongly not taken -> weakly not taken
                        2'b01: bht[indexE] <= 2'b10; // weakly not taken -> weakly taken
                        2'b10: bht[indexE] <= 2'b11; // weakly taken -> strongly taken
                        2'b11: bht[indexE] <= 2'b11; // strongly taken stays
                    endcase
                    // Update BTB with the correct target
                    btb[indexE] <= targetE;
                end else begin
                    // Not taken: decrement state down to 00
                    case (current_state)
                        2'b00: bht[indexE] <= 2'b00; // already strongly not taken
                        2'b01: bht[indexE] <= 2'b00; // weakly not taken -> strongly not taken
                        2'b10: bht[indexE] <= 2'b01; // weakly taken -> weakly not taken
                        2'b11: bht[indexE] <= 2'b10; // strongly taken -> weakly taken
                    endcase
                end
            end
        end
    end

endmodule
