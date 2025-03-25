/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class regfTestbench : public BaseTestbench
{
protected:
  void
  initializeInputs () override
  {
    top->clk = 1;
    top->a1 = 0x0;
    top->a2 = 0x0;
    top->a3 = 0x0;
    top->we3 = 0;
    top->wd3 = 0x0;
    // output: RD1 and RD2
  }

  void
  tick ()
  {
    top->clk = 0;
    top->eval ();
    tfp->dump (ticks++);

    top->clk = 1;
    top->eval ();
    tfp->dump (ticks++);
  }
};

TEST_F (regfTestbench, RegConnectRegistryA)
{

  int inputreg = 0x12345678;

  top->a3 = 1;
  top->wd3 = inputreg;
  top->we3 = 1;

  top->a1 = 0;
  top->a2 = 0;

  tick ();

  top->a1 = 1;
  top->a2 = 0;

  tick ();

  top->we3 = 0;

  EXPECT_EQ (top->rd1, inputreg);
  EXPECT_EQ (top->rd2, 0);
}

int
main (int argc, char **argv)
{
  top = new Vdut;
  tfp = new VerilatedVcdC;

  Verilated::traceEverOn (true);
  top->trace (tfp, 99);
  tfp->open ("waveform.vcd");

  testing::InitGoogleTest (&argc, argv);
  auto res = RUN_ALL_TESTS ();

  top->final ();
  tfp->close ();

  delete top;
  delete tfp;

  return res;
}