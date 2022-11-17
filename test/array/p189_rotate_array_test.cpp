#include "array/array.h"
#include <gtest/gtest.h>
using namespace std;
using namespace my_array;
TEST(RotateArray, example_1)
{
    vector<int> nums{1, 2, 3};
    rotate(nums, 1);
    vector<int> expected_out{3, 1, 2};
    for (int idx = 0; idx < nums.size(); ++idx)
    {
        EXPECT_EQ(nums[idx], expected_out[idx]);
    }
}

TEST(RotateArray, example_2)
{
    vector<int> nums{1, 2, 3, 4};
    rotate(nums, 2);
    vector<int> expected_out{3, 4, 1, 2};
    for (int idx = 0; idx < nums.size(); ++idx)
    {
        EXPECT_EQ(nums[idx], expected_out[idx]);
    }
}