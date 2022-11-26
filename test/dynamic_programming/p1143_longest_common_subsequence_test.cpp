#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(LongestCommonSubsequence, example_1)
{
    string txt1 = "abcde", txt2 = "ace";
    Solution obj;
    EXPECT_EQ(3, obj.longestCommonSubsequence(txt1, txt2));
}

TEST(LongestCommonSubsequence, example_2)
{
    string txt1 = "pmjghexybyrgzczy", txt2 = "hafcdqbgncrcbihkd";
    Solution obj;
    EXPECT_EQ(4, obj.longestCommonSubsequence(txt1, txt2));
}