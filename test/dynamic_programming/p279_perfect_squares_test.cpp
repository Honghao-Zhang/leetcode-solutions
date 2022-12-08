#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(PerfectSquares, example_1)
{
    Solution obj;
    EXPECT_EQ(3, obj.numSquares(12));
}

TEST(PerfectSquares, example_2)
{
    Solution obj;
    EXPECT_EQ(2, obj.numSquares(13));
}