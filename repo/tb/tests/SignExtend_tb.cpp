/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

class SignExtendTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->instr = 0x0;
        top->ImmSrc = 0x0;
        // output: imm_ext
    }
};

TEST_F(SignExtendTestbench, StypeWorks)
{
    top->instr = 0xFF807890;
    top->ImmSrc = 0x1;

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFFFF1);
}

TEST_F(SignExtendTestbench, ItypeWroks)
{
    top->instr = 0xFFF0A123;
    top->ImmSrc = 0x0;

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFFFFF);
}

TEST_F(SignExtendTestbench, BtypeWroks)
{
    top->instr = 0x80000000;
    top->ImmSrc = 0x2;

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFF000);
}


int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    return res;
}