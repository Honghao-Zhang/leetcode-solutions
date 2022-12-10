#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(PartitionEqualSubSet, example_1)
{
    vector<int> nums{1, 5, 11, 5};
    Solution obj;
    EXPECT_TRUE(obj.canPartition(nums));
}

TEST(PartitionEqualSubSet, example_2)
{
    vector<int> nums{1, 2, 3, 5};
    Solution obj;
    EXPECT_FALSE(obj.canPartition(nums));
}

TEST(PartitionEqualSubSet, example_3)
{
    vector<int> nums{2, 2, 3, 5};
    Solution obj;
    EXPECT_FALSE(obj.canPartition(nums));
}

TEST(PartitionEqualSubSet, example_4)
{
    vector<int> nums{14, 9, 8, 4, 3, 2};
    Solution obj;
    EXPECT_TRUE(obj.canPartition(nums));
}