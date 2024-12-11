/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class control_unitTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->instr = 0x0;
        top->zero = 0;
    }
};

TEST_F(control_unitTestbench, lwWorksTest)
{
    top->instr = 0b0000011;
    top->zero = 0;

    top->eval();

    EXPECT_EQ(top->PCsrc, 0);
    EXPECT_EQ(top->ResultSrc, 1);
    EXPECT_EQ(top->MemWrite, 0);
    EXPECT_EQ(top->ALUControl, 0b000);
    EXPECT_EQ(top->ALUSrc, 1);
    EXPECT_EQ(top->ImmSrc, 0b00);
    EXPECT_EQ(top->RegWrite, 1);
}

TEST_F(control_unitTestbench, swWorksTest)
{
    top->instr = 0b0100011;
    top->zero = 0;

    top->eval();

    EXPECT_EQ(top->PCsrc, 0);
    // EXPECT_EQ(top->ResultSrc, 1);
    EXPECT_EQ(top->MemWrite, 1);
    EXPECT_EQ(top->ALUControl, 0b000);
    EXPECT_EQ(top->ALUSrc, 1);
    EXPECT_EQ(top->ImmSrc, 0b01);
    EXPECT_EQ(top->RegWrite, 0);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    return res;
}