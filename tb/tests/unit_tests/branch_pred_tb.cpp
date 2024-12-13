#include "base_testbench.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class BranchPredTestbench : public BaseTestbench {
protected:
    void initializeInputs() override {
        top->clk = 1;
        top->reset = 1;
        top->pcF = 0;
        top->pcE = 0;
        top->branch_valid = 0;
        top->branch_taken = 0;
        top->targetE = 0;
    }


    void tick() {
        top->clk = 0;
        top->eval();
        tfp->dump(ticks++);
        top->clk = 1;
        top->eval();
        tfp->dump(ticks++);
    }
};

// Test that the predictor starts off predicting not taken and transitions after multiple taken branches
TEST_F(BranchPredTestbench, BasicPredictionTest) {
    // Bring out of reset
    initializeInputs();
    tick(); // latch reset state
    top->reset = 0;
    tick(); // apply reset removal

    // Initially, at pcF = 0, we expect not taken prediction
    top->pcF = 0x100;  // arbitrary PC
    top->eval();
    EXPECT_EQ(top->branch_predictF, 0) << "Initially should predict not taken.";
    EXPECT_EQ(top->branch_targetF, (uint32_t)0x104) << "Initially target should be pcF+4";

    // Let's define the branch at pcE=0x100, say it was taken multiple times
    // This should move predictor's saturating counter towards taken.
    uint32_t branch_pc = 0x100;
    uint32_t branch_target = 0x200; // predicted target to set
    top->pcE = branch_pc;
    top->branch_valid = 1;
    top->branch_taken = 1;
    top->targetE = branch_target;

    // Apply several taken updates to push the counter towards strongly taken
    for (int i = 0; i < 4; i++) {
        tick();
    }

    // Now stop asserting branch_valid so we can check new prediction
    top->branch_valid = 0;
    top->branch_taken = 0;

    // Fetch again from pcF = 0x100 and see if we now predict taken
    top->pcF = branch_pc;
    top->eval();
    // After multiple taken outcomes, we should see the predictor guess taken
    EXPECT_EQ(top->branch_predictF, 1) << "After training, should predict taken.";
    EXPECT_EQ(top->branch_targetF, branch_target) << "After training, target should match what we stored.";

    // Done with test
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