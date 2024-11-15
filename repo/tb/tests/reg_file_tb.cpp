/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class reg_fileTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 1;
        top->ad1 = 0x0;
        top->ad2 = 0x0;
        top->as3 = 0x0;
        top->RegWrite = 0;
        top->WD = 0x0;
        // output: RD1 and RD2
    }
};

void runSimulation(int num_cycles = 1)
    {
        // Run simuation for one clock cycle
        for (int i = 0; i < num_cycles; ++i)
        {
            // dump variables into VCD file and toggle clock
            for (int clk = 0; clk < 2; ++clk)
            {
                top->eval();
                tfp->dump(2*ticks + clk);
                top->clk = !top->clk;
            }

            ticks++;

            if (Verilated::gotFinish())
            {
                exit(0);
            }
        }
    }

TEST_F(reg_fileTestbench, as3Test)
{
    
    int inputreg = 0x12345678;

    top->as3 = 1;
    top->WD = inputreg;
    top->RegWrite = 1;

    top->ad1 = 0;
    top->ad2 = 0;

    runSimulation(1);

    top->ad1 = 1;
    top->ad2 = 0;

    runSimulation(1);

    EXPECT_EQ(top->RD1, inputreg);
    EXPECT_EQ(top->RD2, 0);
}


int main(int argc, char **argv)
{
    top = new Vdut;
    tfp = new VerilatedVcdC;

    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    tfp->close();

    delete top;
    delete tfp;

    return res;
}