#include "substring/substring.h"
#include <gtest/gtest.h>
using namespace std;
using namespace substring;

TEST(MinWindowSubStr, example_1)
{
    string s = "ADOBECODEBANC", t = "ABC";
    string expected = "BANC";
    Solution obj;
    EXPECT_TRUE(expected == obj.minWindow(s, t));
}

TEST(MinWindowSubStr, example_2)
{
    string s = "a", t = "aa";
    string expected = "";
    Solution obj;
    EXPECT_TRUE(expected == obj.minWindow(s, t));
}

TEST(MinWindowSubStr, example_3)
{
    string s = "a", t = "b";
    string expected = "";
    Solution obj;
    EXPECT_TRUE(expected == obj.minWindow(s, t));
}

TEST(MinWindowSubStr, example_4)
{
    string s = "a", t = "a";
    string expected = "a";
    Solution obj;
    EXPECT_TRUE(expected == obj.minWindow(s, t));
}