module hazard_unit(
    // inputs
    input  logic [4:0]      Rs1D,
    input  logic [4:0]      Rs2D,
    input  logic [4:0]      Rs1E,
    input  logic [4:0]      Rs2E,
    input  logic [4:0]      RdE,
    input  logic            Hazard_PCsrc,
    input  logic [1:0]      ResultSrcE,
    input  logic [4:0]      RdM,
    input  logic [4:0]      RdW,
    input  logic            RegWriteM,
    input  logic            RegWriteW,

    // outputs
    output logic            StallF,
    output logic            StallD,
    output logic            FlushD,
    output logic            FlushE,
    output logic [1:0]      ForwardAE,
    output logic [1:0]      ForwardBE            
);

logic lwStall;

always_comb begin

    // For forwarding, we have:
    // 2'b10 -> forwarding from memory stage, after alu (setting ALUResultM as aluop)
    // 2'b01 -> forwarding from write back stage, after data mem (setting ResultW as aluop)
    // 2'b00 -> no forwarding (simply take regf output)

    // deciding whether to forward rd1
    if (((Rs1E == RdM) && RegWriteM) && (Rs1E != 0)) begin
        ForwardAE = 2'b10;
    end
    else if (((Rs1E == RdW) && RegWriteW) && (Rs1E != 0)) begin 
        ForwardAE = 2'b01;
    end
    else begin 
        ForwardAE = 2'b00;
    end


    // deciding whethere to forward rd2
    if (((Rs2E == RdM) && RegWriteM) && (Rs2E != 0)) begin
        ForwardBE = 2'b10;
    end
    else if (((Rs2E == RdW) && RegWriteW) && (Rs2E != 0)) begin 
        ForwardBE = 2'b01;
    end
    else begin 
        ForwardBE = 2'b00;
    end

    
    // Sll when a load hazard occurs:
    lwStall = ResultSrcE[0] && ((Rs1D == RdE) | (Rs2D == RdE));

    StallF = lwStall;
    StallD = lwStall;

    FlushD = Hazard_PCsrc;
    FlushE = (Hazard_PCsrc | lwStall);
end

endmodule
