#include <cstdlib>
#include <utility>

#include "cpu_testbench.h"

#define CYCLES 10000

TEST_F(CpuTestbench, TestAddiBne)
{
    setupTest("1_addi_bne");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 254);
}

TEST_F(CpuTestbench, TestLiAdd)
{
    setupTest("2_li_add");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 1000);
}

TEST_F(CpuTestbench, TestLbuSb)
{
    setupTest("3_lbu_sb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 300);
}

TEST_F(CpuTestbench, TestJalRet)
{
    setupTest("4_jal_ret");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 53);
}

TEST_F(CpuTestbench, TestDmem)
{
    setupTest("6_dmem");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 138);
}

TEST_F(CpuTestbench, TestAddr)
{
    setupTest("7_addr");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x10100);
}

TEST_F(CpuTestbench, TestSB)
{
    setupTest("8_sb");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x4E);
}

TEST_F(CpuTestbench, TestPipelineTiming)
{
    setupTest("9_pipeline");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0x4E);
}

TEST_F(CpuTestbench, TestHalfWords)
{
    setupTest("13_halfW");
    initSimulation();
    runSimulation(CYCLES);
    EXPECT_EQ(top_->a0, 0xBE01);
}

// TEST_F(CpuTestbench, TestBuild)
// {
//     setupTest("10_build");
//     setData("reference/gaussian.mem");
//     initSimulation();
//     runSimulation(CYCLES * 100);
//     EXPECT_EQ(top_->a0, 200);
// }

// TEST_F(CpuTestbench, TestBuild)
// {
//     setupTest("11_basepdf");
//     setData("reference/gaussian.mem");
//     initSimulation();
//     runSimulation(CYCLES * 100);
//     EXPECT_EQ(top_->a0, 200);
// }

// TEST_F(CpuTestbench, TestDisplay)
// {
//     setupTest("12_display");
//     setData("reference/gaussian.mem");
//     initSimulation();
//     runSimulation(CYCLES * 100);
//     EXPECT_EQ(top_->a0, 0);
// }



TEST_F(CpuTestbench, TestPdf)
{
    setupTest("5_pdf");
    setData("reference/gaussian.mem");
    initSimulation();
    runSimulation(CYCLES * 100);
    EXPECT_EQ(top_->a0, 15363);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
