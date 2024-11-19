/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class pcTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->branch_PC = 0;
        top->inc_pc = 0;
        top->PCsrc = 0;

        // output: out
    }

    void tick()
    {
        top->clk = 0; // Clock low
        top->eval();
        tfp->dump(ticks++);

        top->clk = 1; // Clock high
        top->eval();
        tfp->dump(ticks++);
    }
};

TEST_F(pcTestbench, pcWorksTest)
{
    top->branch_PC = 0;
    top->inc_pc = 4;
    top->PCsrc = 0;

    top->eval();

    tick();

    top->eval();

    EXPECT_EQ(top->next_PC, 4);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    return res;
}