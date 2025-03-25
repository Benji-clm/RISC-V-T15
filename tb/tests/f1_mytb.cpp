#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

#include "vbuddy.cpp"
#define MAX_SIM_CYC 100000

int
main (int argc, char **argv, char **env)
{
  int simcyc;
  int tick;
  int lights = 0;

  std::ignore = system (("./assemble.sh asm/f1.s"));

  // Create empty file for data memory
  std::ignore = system ("touch data.hex");

  Verilated::commandArgs (argc, argv);
  // init top verilog instance

  Vtop *top = new Vtop;
  // init trace dump

  Verilated::traceEverOn (true);
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");

  // init Vbuddy
  if (vbdOpen () != 1)
    return (-1);
  vbdHeader ("F1 Lights");
  vbdSetMode (1); // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->trigger = 0;

  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc = 0; simcyc < MAX_SIM_CYC; simcyc++)
    {
      // dump variables into VCD file and toggle clock
      for (tick = 0; tick < 2; tick++)
        {
          tfp->dump (2 * simcyc + tick);
          top->clk = !top->clk;
          top->eval ();
        }

      // Display toggle neopixel
      vbdBar (top->a0 & 0xFF);

      vbdHex (4, (int (top->a0) >> 16) & 0xF);
      vbdHex (3, (int (top->a0) >> 8) & 0xF);
      vbdHex (2, (int (top->a0) >> 4) & 0xF);
      vbdHex (1, (int (top->a0)) & 0xF);

      // set up input signals of testbench
      top->trigger = vbdFlag (); // trigger
      vbdCycle (simcyc);

      if (Verilated::gotFinish () || vbdGetkey () == '`')
        break;
    }

  vbdClose ();
  tfp->close ();
  if (top)
    delete top;
  if (tfp)
    delete tfp;
  std::ignore = std::remove ("data.hex");
  std::ignore = std::remove ("program.hex");

  exit (0);
}
