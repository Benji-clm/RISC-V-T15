#include "Vtop.h"               
#include "verilated.h"          
#include "verilated_vcd_c.h"    

#include "vbuddy.cpp"         
#define MAX_SIM_CYC 100000       // max cycles
#define INIT_DELAY 3             // delay before reset
#define COUNTER_LIMIT 8          // counter limit

int main(int argc, char **argv, char **env) {
    int simcyc, tick, delay_counter = 0, main_counter = 0, reset = 1;

    system("./compile.sh f1.S");  // compile code

    Verilated::commandArgs(argc, argv); // parse args
    Verilated::traceEverOn(true);        // enable trace

    Vtop* top = new Vtop;             // verilog instance
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);              // enable signal trace
    tfp->open("waveform.vcd");        // open file

    if (vbdOpen() != 1) return -1;    // init vbuddy
    vbdHeader("F1 lights - vbuddy");  // vbuddy header
    vbdSetMode(1);                    // flag mode

    top->clk = 1; top->trigger = 0;    // init inputs

    for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++) {
        for (tick = 0; tick < 2; tick++) {
            tfp->dump(2 * simcyc + tick);   // dump trace
            top->clk = !top->clk;           // toggle clk
            top->eval();                    // eval design
        }

        vbdBar(top->a0 & 0xFF);  // show lower byte on led bar
        vbdHex(4, (int(top->a0) >> 16) & 0xF);  // upper 4 bits
        vbdHex(3, (int(top->a0) >> 8) & 0xF);
        vbdHex(2, (int(top->a0) >> 4) & 0xF);
        vbdHex(1, (int(top->a0)) & 0xF);  // lower 4 bits

        if (simcyc == 5) {   // reset after 5 cycles
            reset = 0;
            top->rst = reset;
        }

        if (top->rst == 0) {
            if (top->counter == COUNTER_LIMIT) {
                delay_counter++;
                if (delay_counter == INIT_DELAY) {
                    delay_counter = 0;
                    main_counter++;  // after delay, inc main counter
                }
            } else {
                main_counter++;  // inc main counter
            }
        }

        if (main_counter >= 3) break;  // end after 3 loops

        top->trigger = vbdFlag();  // vbuddy trigger
        vbdCycle(simcyc);          // update cycle on vbuddy

        if (Verilated::gotFinish() || vbdGetkey() == '`') break;  // exit
    }

    vbdClose();   // close vbuddy
    tfp->close(); // close trace file
    delete tfp;   
    delete top;  

    return 0;
}
