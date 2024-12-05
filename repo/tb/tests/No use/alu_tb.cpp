#include "base_testbench.h"

#define ALUop_ADD       0x0
#define ALUop_SUB       0x1
#define ALUop_AND       0x2
#define ALUop_OR        0x3
#define ALUop_XOR       0x4
#define ALUop_LSL       0x5
#define ALUop_LSR       0x6
#define ALUop_ASR       0x7
#define ALUop_SLT       0x8
#define ALUop_SLTU      0x9
#define ALUop_B         0xA

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class ALUTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->ALUop1 = 0;
        top->ALUop2 = 0;
        top->ALUctrl = 0;
        // output: ALUout & eq
    }
};

TEST_F(ALUTestbench, AddWorksTest)
{
    top->ALUctrl = ALUop_ADD; // `ALUop_ADD`
    top->ALUop1 = 10;
    top->ALUop2 = 20;

    top->eval();

    EXPECT_EQ(top->ALUout, 30);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, SubWorksTest)
{
    top->ALUctrl = ALUop_SUB; // `ALUop_SUB`
    top->ALUop1 = 50;
    top->ALUop2 = 20;

    top->eval();

    EXPECT_EQ(top->ALUout, 30);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, AndWorksTest)
{
    top->ALUctrl = ALUop_AND; // `ALUop_AND`
    top->ALUop1 = 0b1010;
    top->ALUop2 = 0b1100;

    top->eval();

    EXPECT_EQ(top->ALUout, 0b1000);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, OrWorksTest)
{
    top->ALUctrl = ALUop_OR; // `ALUop_OR`
    top->ALUop1 = 0b1010;
    top->ALUop2 = 0b1100;

    top->eval();

    EXPECT_EQ(top->ALUout, 0b1110);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, SltSignedWorksTest)
{
    top->ALUctrl = ALUop_SLT; // `ALUop_SLT`
    top->ALUop1 = static_cast<int32_t>(-10);
    top->ALUop2 = static_cast<int32_t>(20);

    top->eval();

    EXPECT_EQ(top->ALUout, 1);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, LslWorksTest)
{
    top->ALUctrl = ALUop_LSL; // `ALUop_LSL`
    top->ALUop1 = 1;
    top->ALUop2 = 3;

    top->eval();

    EXPECT_EQ(top->ALUout, 8);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, LsrWorksTest)
{
    top->ALUctrl = ALUop_LSR; // `ALUop_LSR`
    top->ALUop1 = 16;
    top->ALUop2 = 2;

    top->eval();

    EXPECT_EQ(top->ALUout, 4);
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, AsrWorksTest)
{
    top->ALUctrl = ALUop_ASR; // `ALUop_ASR`
    top->ALUop1 = static_cast<int32_t>(-16);
    top->ALUop2 = 2;

    top->eval();

    EXPECT_EQ(top->ALUout, static_cast<int32_t>(-4));
    EXPECT_EQ(top->eq, 0);
}

TEST_F(ALUTestbench, EqFlagWorksTest)
{
    top->ALUctrl = ALUop_SUB; // `ALUop_SUB`
    top->ALUop1 = 30;
    top->ALUop2 = 30;

    top->eval();

    EXPECT_EQ(top->ALUout, 0); // Result is zero
    EXPECT_EQ(top->eq, 1);     // eq flag should be set
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
