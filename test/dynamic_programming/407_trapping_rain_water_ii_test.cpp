#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(TrappingRainWaterII, example_1)
{
    vector<vector<int>> height{{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    Solution obj;
    EXPECT_EQ(4, obj.trapRainWater(height));
}
