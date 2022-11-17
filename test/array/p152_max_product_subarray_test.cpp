#include "array/array.h"
#include <gtest/gtest.h>

using namespace my_array;

TEST(MaxProductSubarray, example_1)
{
    std::vector<int> nums{2, 3, -2, 4};
    EXPECT_EQ(6, maxProductSubarray(nums));
}

TEST(MaxSumSubarray, example_1)
{
    std::vector<int> nums{2, 3, -2, 4};
    EXPECT_EQ(7, maxSumSubarray(nums));
    auto subarray = findMaxSumSubarray(nums);
}