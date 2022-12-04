#include "array/array.h"
#include <gtest/gtest.h>
using namespace std;
using namespace my_array;

TEST(SlidingWindowMaximum, example_1)
{
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto res = my_array::maxSlidingWindow(nums, k);
    vector<int> expected{3, 3, 5, 5, 6, 7};
    EXPECT_EQ(res.size(), expected.size());
    for (auto idx = 0; idx < res.size(); ++idx)
    {
        EXPECT_EQ(res[idx], expected[idx]);
    }
}
