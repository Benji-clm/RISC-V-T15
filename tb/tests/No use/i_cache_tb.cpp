#include "base_testbench.h"


Vdut*top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class ICacheTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->reset = 1;
        top->pc = 0;
    }

    void toggleClock()
    {
        top->clk = !top->clk;
        top->eval();
        tfp->dump(ticks++);
    }
};

TEST_F(ICacheTestbench, CacheMissTest)
{
    top->reset = 1;
    top->eval();
    toggleClock();
    top->reset = 0;

    // Simulate access to address 0x0000 (expected miss)
    top->pc = 0x0000;
    toggleClock(); // First clock cycle
    EXPECT_EQ(top->instr, 0); // Replace 0 with the expected value for a cache miss
}

TEST_F(ICacheTestbench, CacheHitTest)
{
    top->reset = 1;
    top->eval();
    toggleClock();
    top->reset = 0;

    // Access address 0x0000 (cache miss expected first)
    top->pc = 0x0000;
    toggleClock();
    EXPECT_EQ(top->instr, 0); // Replace with the expected value

    // Access the same address again (cache hit expected)
    top->pc = 0x0000;
    toggleClock();
    EXPECT_EQ(top->instr, 0); // Replace with the expected value
}

TEST_F(ICacheTestbench, CacheFillAndEvictTest)
{
    top->reset = 1;
    top->eval();
    toggleClock();
    top->reset = 0;

    // Fill the cache with different addresses
    for (int i = 0; i < 256; i++) { // Assuming CACHE_SIZE = 256
        top->pc = i * 4; // Sequential access to fill cache
        toggleClock();
    }

    // Access an address outside the filled range (expected eviction)
    top->pc = 0x1000;
    toggleClock();
    EXPECT_EQ(top->instr, 0); // Replace with the expected value for evicted data
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
