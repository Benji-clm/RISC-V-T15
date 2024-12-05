module i_cache #(
    parameter DATA_WIDTH = 32,
    parameter NUM_BLOCKS = 64 // Number of cache lines
)(
    input logic clk,
    input logic rst,

    // CPU Interface
    input logic [DATA_WIDTH-1:0] pc,         // PC from fetch stage
    input logic fetch_req,                  // Fetch request signal
    output logic [DATA_WIDTH-1:0] instr,    // Fetched instruction
    output logic hit,                       // Cache hit
    output logic miss,                      // Cache miss

    // i_mem Interface
    output logic mem_req,                   // Memory request signal
    output logic [DATA_WIDTH-1:0] mem_pc,   // Address to i_mem
    input logic [DATA_WIDTH-1:0] mem_instr, // Instruction fetched from i_mem
    input logic mem_valid                   // i_mem data valid signal
);

    // Cache structures
    typedef struct packed {
        logic valid;                        // Valid bit
        logic [DATA_WIDTH-3:0] tag;         // Tag (address minus offset bits)
        logic [DATA_WIDTH-1:0] data;        // Cached instruction
        logic [5:0] lru_counter;            // LRU counter for eviction
    } cache_line_t;

    cache_line_t cache_lines [NUM_BLOCKS-1:0];

    // Signals
    logic [DATA_WIDTH-3:0] tag = pc[DATA_WIDTH-1:2]; // Extract tag from PC
    logic [5:0] selected_index;                      // Index of block to evict
    logic [DATA_WIDTH-1:0] instr_comb;               // Intermediate combinational signal for instruction

    // State machine for cache
    typedef enum logic [1:0] {IDLE, FETCH_MEM, UPDATE_CACHE} state_t;
    state_t state;

    // Reset logic and state machine
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset all cache lines
            for (logic [5:0] i = 0; i < NUM_BLOCKS; i++) begin
                cache_lines[i].valid <= 0;
                cache_lines[i].lru_counter <= 0;
            end
            state <= IDLE;
            mem_req <= 0;
            instr <= 32'b0;
        end else begin
            case (state)
                IDLE: begin
                    if (fetch_req) begin
                        if (hit) begin
                            instr <= instr_comb; // Forward the fetched instruction
                            state <= IDLE;
                        end else begin
                            state <= FETCH_MEM;  // Fetch from memory
                            mem_req <= 1;
                            mem_pc <= pc;
                        end
                    end
                end
                FETCH_MEM: begin
                    if (mem_valid) begin
                        // Data fetched, proceed to cache update
                        state <= UPDATE_CACHE;
                        mem_req <= 0;
                    end
                end
                UPDATE_CACHE: begin
                    // Update cache and go back to IDLE
                    cache_lines[selected_index].valid <= 1;
                    cache_lines[selected_index].tag <= tag;
                    cache_lines[selected_index].data <= mem_instr;
                    cache_lines[selected_index].lru_counter <= 0;

                    // Increment LRU counters for other lines
                    for (logic [5:0] j = 0; j < NUM_BLOCKS; j++) begin
                        if (cache_lines[j].valid && j != selected_index) begin
                            cache_lines[j].lru_counter <= cache_lines[j].lru_counter + 1;
                        end
                    end

                    instr <= mem_instr; // Provide the fetched instruction
                    state <= IDLE;
                end
            endcase
        end
    end

    logic [5:0] i; // Declare loop variable outside
    always_comb begin
        hit = 0;
        miss = 1;
        instr_comb = 32'b0;
        for (i = 0; i < NUM_BLOCKS; i++) begin
            if (cache_lines[i].valid && cache_lines[i].tag == tag) begin
                hit = 1;
                miss = 0;
                instr_comb = cache_lines[i].data;
                break;
            end
        end
    end

    // LRU replacement logic
    logic [5:0] j; // Declare loop variable outside
    always_comb begin
        for (j = 0; j < NUM_BLOCKS; j++) begin
            if (cache_lines[j].valid && j != selected_index) begin
                cache_lines[j].lru_counter = cache_lines[j].lru_counter + 1;
            end
        end
    end


endmodule
