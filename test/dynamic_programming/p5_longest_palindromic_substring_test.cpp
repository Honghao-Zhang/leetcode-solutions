#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(LongestPalindromicSubstring, example_1)
{
    string s = "babad";
    Solution obj;
    auto output = obj.longestPalindrome(s);
    EXPECT_TRUE("aba" == output || "bab" == output);
}
