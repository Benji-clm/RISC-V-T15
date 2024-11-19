#include "base_testbench.h" // Base testbench (similar to the SignExtendTestbench)

Vdut *top;             // Pointer to the DUT
VerilatedVcdC *tfp;        // For tracing
unsigned int ticks = 0;    // Simulation time ticks

class CounterTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->next_PC = 0x0; // Default to no increment
    }

    void tick()
    {
        // Toggle clock
        top->clk = 0;
        top->eval();
        tfp->dump(ticks++);

        top->clk = 1;
        top->eval();
        tfp->dump(ticks++);
    }

};

// Test: Reset behavior
TEST_F(CounterTestbench, ResetWorks)
{
    top->rst = 1;
    tick(); // Apply reset
    tick();

    EXPECT_EQ(top->p_count, 0x0);

    top->rst = 0; // Deassert reset
}

// Test: Increment by 4
TEST_F(CounterTestbench, IncrementByFour)
{
    top->rst = 1;
    tick();
    top->rst = 0;

    top->next_PC = 0x4; // Increment by 4
    tick();
    EXPECT_EQ(top->p_count, 0x4);

    tick();
    EXPECT_EQ(top->p_count, 0x8);
}

// Test: Dynamic Increment
TEST_F(CounterTestbench, DynamicIncrement)
{
    top->rst = 1;
    tick();
    top->rst = 0;

    top->next_PC = 0x2; // Increment by 2
    tick();
    EXPECT_EQ(top->p_count, 0x2);

    top->next_PC = 0x6; // Increment by 6
    tick();
    EXPECT_EQ(top->p_count, 0x8);
}

// Test: Reset after Increment
TEST_F(CounterTestbench, ResetAfterIncrement)
{
    top->rst = 1;
    tick();
    top->rst = 0;

    top->next_PC = 0x4;
    tick();
    EXPECT_EQ(top->p_count, 0x4);

    top->rst = 1; // Apply reset
    tick();
    EXPECT_EQ(top->p_count, 0x0);
}

int main(int argc, char **argv)
{
    // Instantiate DUT and tracer
    top = new Vdut  ;
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
