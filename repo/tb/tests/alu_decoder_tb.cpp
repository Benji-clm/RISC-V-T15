/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class alu_decoderTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->op = 0x0;
        top->funct3 = 0x0;
        top->funct7 = 0x0;
        top->ALUOp = 0x0;
        // Output: ALUControl
    }
};

TEST_F(alu_decoderTestbench, lwswWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x0;
    top->funct7 = 0x0;
    top->ALUOp = 0x0;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x0);
}

TEST_F(alu_decoderTestbench, beqWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x0;
    top->funct7 = 0x0;
    top->ALUOp = 0x1;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x1);
}

TEST_F(alu_decoderTestbench, addWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x0;
    top->funct7 = 0x0;
    top->ALUOp = 0x2;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x0);
}

TEST_F(alu_decoderTestbench, subWorksTest)
{
    top->op = 0x1;
    top->funct7 = 0x1;
    top->funct3 = 0x0;
    top->ALUOp = 0x2;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x1);
}

TEST_F(alu_decoderTestbench, sltWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x2;
    top->funct7 = 0x0;
    top->ALUOp = 0x2;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x5);
}

TEST_F(alu_decoderTestbench, orWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x6;
    top->funct7 = 0x0;
    top->ALUOp = 0x2;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x3);
}

TEST_F(alu_decoderTestbench, andWorksTest)
{
    top->op = 0x0;
    top->funct3 = 0x7;
    top->funct7 = 0x0;
    top->ALUOp = 0x2;

    top->eval();

    EXPECT_EQ(top->ALUControl, 0x2);
}

int main(int argc, char **argv)
{
    Verilated::commandArgs(argc, argv);
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    return res;
}