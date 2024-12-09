module i_cache #(
    parameter DATA_WIDTH = 32,
    parameter CACHE_SIZE = 256, // Number of cache sets
    parameter LINE_SIZE = 4,    // Number of instructions per cache line
    parameter ASSOC = 2,        // Associativity (number of ways)
    parameter ADDR_WIDTH = 32
) (
    input  logic                     clk,
    input  logic                     reset,
    input  logic [ADDR_WIDTH-1:0]    pc,
    output logic [DATA_WIDTH-1:0]    instr
);

    // Cache line structure
    typedef struct packed {
        logic                        valid;  // Valid bit
        logic [ADDR_WIDTH-$clog2(CACHE_SIZE*LINE_SIZE)-1:0] tag; // Tag
        logic [DATA_WIDTH*LINE_SIZE-1:0] data; // Cache line data
    } cache_line_t;

    // Cache set structure
    typedef struct packed {
        cache_line_t [ASSOC-1:0] ways; // Associative ways
        logic [ASSOC-1:0] lru;         // LRU bits
    } cache_set_t;

    // Cache memory
    cache_set_t cache_mem [CACHE_SIZE];

    // Signals for i_mem
    logic [DATA_WIDTH-1:0] mem_instr;
    logic [DATA_WIDTH*LINE_SIZE-1:0] mem_data;
    logic [ADDR_WIDTH-1:0] aligned_pc;

    // Decode PC into index, tag, and block offset
    logic [$clog2(CACHE_SIZE)-1:0]  index;
    logic [ADDR_WIDTH-$clog2(CACHE_SIZE*LINE_SIZE)-1:0] tag;
    logic [$clog2(LINE_SIZE)-1:0]  block_offset;

    assign index = pc[$clog2(CACHE_SIZE)-1:0];
    assign tag = pc[ADDR_WIDTH-1:$clog2(CACHE_SIZE*LINE_SIZE)];
    assign block_offset = pc[$clog2(LINE_SIZE)-1:0];
    assign aligned_pc = pc & ~($clog2(LINE_SIZE)-1); // Align PC to cache line boundary

    // i_mem instance
    i_mem #(DATA_WIDTH) mem_inst (
        .pc(aligned_pc),
        .instr(mem_instr)
    );

    // Drive mem_data (fetch multiple instructions for a cache line)
    always_comb begin
        for (int i = 0; i < LINE_SIZE; i++) begin
            mem_data[(i*DATA_WIDTH) +: DATA_WIDTH] = mem_instr; // Simplified for single-instruction i_mem
        end
    end

    // Cache hit/miss detection
    logic hit;
    logic [ASSOC-1:0] hit_way;

    always_comb begin
        hit = 0;
        hit_way = 0;
        for (int i = 0; i < ASSOC; i++) begin
            if (cache_mem[index].ways[i].valid && cache_mem[index].ways[i].tag == tag) begin
                hit = 1;
                hit_way[i] = 1;
            end
        end
    end

    // Data output logic
    always_comb begin
        instr = mem_instr; // Default value for instr
        if (hit) begin
            for (int i = 0; i < ASSOC; i++) begin
                if (hit_way[i]) begin
                    instr = cache_mem[index].ways[i].data[(block_offset*DATA_WIDTH) +: DATA_WIDTH];
                end
            end
        end
    end

    // Cache refill and replacement logic
    always_ff @(posedge clk) begin
        if (reset) begin
            // Invalidate all cache lines
            for (int i = 0; i < CACHE_SIZE; i++) begin
                for (int j = 0; j < ASSOC; j++) begin
                    cache_mem[i].ways[j].valid <= 0;
                    cache_mem[i].ways[j].tag <= 0;
                    cache_mem[i].ways[j].data <= 0;
                end
            end
        end else if (!hit) begin
            // On a miss, load a new cache line from memory
            logic [$clog2(ASSOC)-1:0] lru_way;
            lru_way = 0;
            for (int i = 1; i < ASSOC; i++) begin
                if (cache_mem[index].lru[i] > cache_mem[index].lru[lru_way]) begin
                    lru_way = i[$clog2(ASSOC)-1:0];
                end
            end

            // Replace the LRU way
            cache_mem[index].ways[lru_way].data <= mem_data;
            cache_mem[index].ways[lru_way].tag <= tag;
            cache_mem[index].ways[lru_way].valid <= 1;

            // Update LRU
            for (int i = 0; i < ASSOC; i++) begin
                cache_mem[index].lru[i] <= (i[$clog2(ASSOC)-1:0] == lru_way) ? 0 : cache_mem[index].lru[i] + 1;
            end
        end
    end

endmodule
