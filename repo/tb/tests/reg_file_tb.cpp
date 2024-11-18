
#include "base_testbench.h"  // Base testbench
// For waveform tracing

Vdut *top;              // Pointer to the DUT
VerilatedVcdC *tfp;          // For tracing
unsigned int ticks = 0;      // Simulation time ticks

class RegFileTestbench : public BaseTestbench {
protected:
    void initializeInputs() override {
        top->clk = 0;
        top->ad1 = 0;
        top->ad2 = 0;
        top->as3 = 0;
        top->RegWrite = 0;
        top->ALUout = 0;
    }

    void tick() {
        top->clk = 0; // Clock low
        top->eval();
        tfp->dump(ticks++);

        top->clk = 1; // Clock high
        top->eval();
        tfp->dump(ticks++);
    }
};

// Test: Write and read back from register
TEST_F(RegFileTestbench, WriteAndRead) {
    top->as3 = 5;        // Write to register 5
    top->ALUout = 0xDEADBEEF; // Write data
    top->RegWrite = 1;   // Enable write
    tick();              // Perform write

    top->RegWrite = 0;   // Disable write
    top->ad1 = 5;        // Read from register 5
    tick();

    EXPECT_EQ(top->rd1, 0xDEADBEEF); // Check the read value
}

// Test: Read from multiple registers
TEST_F(RegFileTestbench, MultiRegisterRead) {
    // Write to two registers
    top->as3 = 5;
    top->ALUout = 0x12345678;
    top->RegWrite = 1;
    tick();

    top->as3 = 10;
    top->ALUout = 0x87654321;
    tick();

    // Disable write and read from both registers
    top->RegWrite = 0;
    top->ad1 = 5;
    top->ad2 = 10;
    tick();

    EXPECT_EQ(top->rd1, 0x12345678); // Check first register
    EXPECT_EQ(top->rd2, 0x87654321); // Check second register
}

// Test: Ensure register 0 always reads as 0
TEST_F(RegFileTestbench, ZeroRegisterRead) {
    top->as3 = 0;
    top->ALUout = 0xABCDEF01;
    top->RegWrite = 1;
    tick();

    top->RegWrite = 0;
    top->ad1 = 0;
    tick();

    EXPECT_EQ(top->rd1, 0x0); // Register 0 should always be 0
}

// Test: Write to register with write disabled
TEST_F(RegFileTestbench, WriteDisabled) {
    top->as3 = 5;
    top->ALUout = 0xBADF00D;
    top->RegWrite = 0; // Write disabled
    tick();

    top->ad1 = 5; // Read from the same register
    tick();

    EXPECT_EQ(top->rd1, 0x0); // No value should have been written
}

int main(int argc, char **argv) {
    // Instantiate DUT and tracer
    top = new Vdut;
    tfp = new VerilatedVcdC;

    // Enable waveform tracing
    Verilated::traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    // Initialize Google Test
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    // Finalize and clean up
    top->final();
    tfp->close();
    delete top;
    delete tfp;

    return res;
}
