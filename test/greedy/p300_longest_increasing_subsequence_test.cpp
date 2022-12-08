#include "greedy/greedy.h"
#include <gtest/gtest.h>

using namespace std;
using namespace greedy;

TEST(LongestIncreasingSubsequence, example_1)
{
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    Solution obj;
    EXPECT_EQ(4, obj.lengthOfLIS(nums));
}

TEST(LongestIncreasingSubsequence, example_2)
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    Solution obj;
    EXPECT_EQ(4, obj.lengthOfLIS(nums));
}

TEST(LongestIncreasingSubsequence, example_3)
{
    vector<int> nums{7, 7, 7, 7, 7, 7, 7};
    Solution obj;
    EXPECT_EQ(1, obj.lengthOfLIS(nums));
}

TEST(LongestIncreasingSubsequence, corner_case_1)
{
    vector<int> nums{9, 10, 0, 11, 12};
    Solution obj;
    EXPECT_EQ(4, obj.lengthOfLIS(nums));
}

TEST(LongestIncreasingSubsequence, corner_case_2)
{
    vector<int> nums{6, 3, 5, 10, 11, 2, 9, 14, 13, 7, 4, 8, 12};
    Solution obj;
    EXPECT_EQ(5, obj.lengthOfLIS(nums));
}
