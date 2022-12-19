#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(TrappingRainWater, example_1)
{
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution obj;
    EXPECT_EQ(6, obj.trap(height));
}

TEST(TrappingRainWater, example_2)
{
    vector<int> height{4, 2, 0, 3, 2, 5};
    Solution obj;
    EXPECT_EQ(9, obj.trap(height));
}