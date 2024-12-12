#include <utility>
#include <cstdio>

#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "vbuddy.cpp" // include vbuddy code
#define MAX_SIM_CYC 1300000

int main(int argc, char **argv, char **env)
{
    int simcyc;     // simulation clock count
    int tick;       // each clk cycle has two ticks for two edges
    int lights = 0; // state to toggle LED lights

    std::ignore = system(("./assemble.sh asm/5_pdf.s"));
    // Copy the data.hex file
    system(("cp reference/triangle.mem data.hex"));

    Verilated::commandArgs(argc, argv);
    // init top verilog instance
    Vtop *top = new Vtop;
    // init trace dump
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("top.vcd");

    // init Vbuddy
    if (vbdOpen() != 1)
        return (-1);
    vbdHeader("Triangle Graph");
    vbdSetMode(1); // Flag mode set to one-shot

    // initialize simulation inputs
    top->clk = 1;

    // run simulation for MAX_SIM_CYC clock cycles
    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++)
    {
        // dump variables into VCD file and toggle clock
        for (tick = 0; tick < 2; tick++)
        {
            tfp->dump(2 * simcyc + tick);
            top->clk = !top->clk;
            top->eval();
        }

        

        if (simcyc > 513530 && (top->a0) < 0x99ec && simcyc % 8 == 0){
            vbdPlot(top->a0, 0, 255);
            vbdCycle(simcyc);
            if(vbdFlag()){
                std::cout << simcyc << std::endl;
            break;
        }
            // vbdHex(4, (int(top->a0) >> 12) & 0xF);
            // vbdHex(3, (int(top->a0) >> 8) & 0xF);
            // vbdHex(2, (int(top->a0) >> 4) & 0xF);
            // vbdHex(1, int(top->a0) & 0xF);
        }
        

        // Exit simulation if Vbuddy or Verilator finishes
        if (Verilated::gotFinish() || vbdGetkey() == '`')
            break;
    }

    vbdClose(); // ++++
    tfp->close();
    if (top) delete top;
    if (tfp) delete tfp;

    std::ignore = std::remove("data.hex");
    std::ignore = std::remove("program.hex");
    
    exit(0);
}
