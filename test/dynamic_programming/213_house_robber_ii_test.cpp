#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(HouseRobberII, example_1)
{
    vector<int> nums{4, 1, 2, 7, 5, 3, 1};
    Solution obj;
    EXPECT_EQ(14, obj.rob(nums));
}

TEST(HouseRobberII, example_2)
{
    vector<int> nums{2, 3, 2};
    Solution obj;
    EXPECT_EQ(3, obj.rob(nums));
}

TEST(HouseRobberII, example_3)
{
    vector<int> nums{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
    Solution obj;
    EXPECT_EQ(16, obj.rob(nums));
}