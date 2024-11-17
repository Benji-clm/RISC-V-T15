/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class ALUTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->in1 = 0x0;
        top->in2 = 0x0;
        top->ALUCtrl = 0x0;
        // output: ALUout & eq
    }
};

TEST_F(ALUTestbench, AddWorksTest)
{
    top->ALUCtrl = 0x0;
    top->in1 = 0x00000001;
    top->in2 = 0x00000004;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x00000005);
    EXPECT_EQ(top->eq, 0x0);
}

TEST_F(ALUTestbench, SubWorksTest)
{
    top->ALUCtrl = 0x1;
    top->in1 = 0x00000011;
    top->in2 = 0x00000001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x00000010);
    EXPECT_EQ(top->eq, 0x0);
}

TEST_F(ALUTestbench, AndWorksTest)
{
    top->ALUCtrl = 0x2;
    top->in1 = 0x00400011;
    top->in2 = 0x00400001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x00400001);
    EXPECT_EQ(top->eq, 0x0);

    top->in1 = 0x000FF000;
    top->in2 = 0x00000001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x00000000);
    EXPECT_EQ(top->eq, 0x1);
}

TEST_F(ALUTestbench, OrWorksTest)
{
    top->ALUCtrl = 0x3;
    top->in1 = 0x00010011;
    top->in2 = 0x000F0001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x000F0011);
    EXPECT_EQ(top->eq, 0x0);
}

TEST_F(ALUTestbench, SLTWorksTest)
{
    top->ALUCtrl = 0x5;
    top->in1 = 0x00000011;
    top->in2 = 0x00000001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x0);
    EXPECT_EQ(top->eq, 0x1);

    top->in1 = 0x00000011;
    top->in2 = 0x000F0001;

    top->eval();

    EXPECT_EQ(top->ALUout, 0x1);
    EXPECT_EQ(top->eq, 0x0);
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