#include "base_testbench.h" 

Vdut *top;            
VerilatedVcdC *tfp;       
unsigned int ticks = 0; 

class IMemTestbench : public BaseTestbench {
protected:
    void initializeInputs() override {
        top->pc = 0; // Initialize program counter to 0
    }

    void tick() {
        // Evaluate DUT
        top->eval();
        tfp->dump(ticks++);
    }
};

// Test: Fetch instruction at PC = 0
TEST_F(IMemTestbench, FetchAtZero) {
    top->pc = 0x0; // Program counter set to 0
    tick();

    EXPECT_EQ(top->instr, 0x0FF00313); // Instruction at PC = 0
}

// Test: Fetch instruction at PC = 4
TEST_F(IMemTestbench, FetchAtFour) {
    top->pc = 0x4; // Program counter set to 4
    tick();

    EXPECT_EQ(top->instr, 0x00000513); // Instruction at PC = 4
}

// Test: Fetch instruction at PC = 8
TEST_F(IMemTestbench, FetchAtEight) {
    top->pc = 0x8; // Program counter set to 8
    tick();

    EXPECT_EQ(top->instr, 0x00000593); // Instruction at PC = 8
}

// Test: Fetch instruction at PC = 12
TEST_F(IMemTestbench, FetchAtTwelve) {
    top->pc = 0xC; // Program counter set to 12
    tick();

    EXPECT_EQ(top->instr, 0x00058513); // Instruction at PC = 12
}

int main(int argc, char **argv) {

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

