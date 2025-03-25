module branch_pred #(
    parameter ADDRESS_WIDTH = 32,
    parameter BHT_ENTRIES   = 64,
    parameter BHT_INDEX_BITS = 6
)(
    input  logic                     clk,
    input  logic                     reset,
    input  logic [ADDRESS_WIDTH-1:0] pcF,
    input  logic [ADDRESS_WIDTH-1:0] pcE,
    input  logic                     branch_valid,
    input  logic                     branch_taken,
    input  logic [ADDRESS_WIDTH-1:0] targetE,

    output logic                     branch_predictF,
    output logic [ADDRESS_WIDTH-1:0] branch_targetF
);

    // Simple state machine from lectures:
    // 00: strongly not taken
    // 01: weakly not taken
    // 10: weakly taken
    // 11: strongly taken
    typedef logic [1:0] bht_state_t;

    bht_state_t bht [0:BHT_ENTRIES-1];

    logic [ADDRESS_WIDTH-1:0] btb [0:BHT_ENTRIES-1];

    // keeping a small table of 64 entries associtating prediction state with each address. 
    wire [BHT_INDEX_BITS-1:0] indexF = pcF[BHT_INDEX_BITS+1:2];
    wire [BHT_INDEX_BITS-1:0] indexE = pcE[BHT_INDEX_BITS+1:2];

    // Prediction at fetch
    bht_state_t stateF;
    always_comb begin
        stateF = bht[indexF];
        if (stateF[1] == 1) begin
            branch_predictF = 1'b1;
            branch_targetF = btb[indexF];
        end else begin
            branch_predictF = 1'b0;
            branch_targetF = pcF + 4;
        end
    end

    always_ff @(negedge clk) begin
        if (reset) begin
            integer i;
            for (i = 0; i < BHT_ENTRIES; i++) begin
                bht[i] <= 2'b00;
                btb[i] <= '0;
            end
        end else begin
            if (branch_valid) begin
                bht_state_t current_state = bht[indexE];
                if (branch_taken) begin
                    case (current_state)
                        2'b00: bht[indexE] <= 2'b01;
                        2'b01: bht[indexE] <= 2'b10;
                        2'b10: bht[indexE] <= 2'b11;
                        2'b11: bht[indexE] <= 2'b11;
                    endcase
                    btb[indexE] <= targetE;
                end else begin
                    case (current_state)
                        2'b00: bht[indexE] <= 2'b00;
                        2'b01: bht[indexE] <= 2'b00;
                        2'b10: bht[indexE] <= 2'b01;
                        2'b11: bht[indexE] <= 2'b10;
                    endcase
                end
            end
        end
    end

endmodule
