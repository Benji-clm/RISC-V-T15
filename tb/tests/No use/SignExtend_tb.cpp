/*
 *  Verifies the results of the sign_extend module, exits with a 0 on success.
 */

#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;

class SignExtendTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->instr = 0x0;
        top->ImmSrc = 0x0;
        // Output: ImmOp
    }
};

TEST_F(SignExtendTestbench, ITypeWorks)
{
    top->instr = 0xFFF0A123; // Instruction with immediate in [31:20]
    top->ImmSrc = 0x0; // `I_TYPE`

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFFFFF); // Sign-extended immediate
}

TEST_F(SignExtendTestbench, STypeWorks)
{
    top->instr = 0xFF807890; // Instruction with immediate in [31:25, 11:7]
    top->ImmSrc = 0x1; // `S_TYPE`

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFFFF1); // Sign-extended immediate
}

TEST_F(SignExtendTestbench, BTypeWorks)
{
    top->instr = 0x80000000; // Instruction for B-type
    top->ImmSrc = 0x2; // `B_TYPE`

    top->eval();

    EXPECT_EQ(top->ImmOp, 0xFFFFF000); // Sign-extended immediate
}

TEST_F(SignExtendTestbench, UTypeWorks)
{
    top->instr = 0x12345000; // Instruction for U-type
    top->ImmSrc = 0x3; // `U_TYPE`

    top->eval();

    EXPECT_EQ(top->ImmOp, 0x12345000); // Zero-extended immediate
}

TEST_F(SignExtendTestbench, JTypeWorks)
{
    top->instr = 0x80000123; // Example instruction
    top->ImmSrc = 0x4; // `J_TYPE`

    top->eval();

    // Expected result:
    // Immediate = {sign_bit, [19:12], [20], [30:21], 0}
    // Sign-extended to 32 bits.
    EXPECT_EQ(top->ImmOp, 0xFFFFF848); 

    // Debugging info
    std::cout << "Instr: 0x" << std::hex << top->instr << ", ImmOp: 0x" << std::hex << top->ImmOp << std::endl;
}


TEST_F(SignExtendTestbench, NETypeWorks)
{
    top->instr = 0xDEADBEEF; // Irrelevant for NE_TYPE
    top->ImmSrc = 0x5; // `NE_TYPE`

    top->eval();

    EXPECT_EQ(top->ImmOp, 0x0); // No extension should result in 0
}

int main(int argc, char **argv)
{
    top = new Vdut; // Updated module instance
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