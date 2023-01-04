#include "backtracking/backtracking.h"
#include <gtest/gtest.h>
using namespace std;
using namespace backtracking;

TEST(DecodeWays, example_1)
{
    string s = "12";
    Solution obj;
    EXPECT_EQ(2, obj.numDecodings(s));
}

TEST(DecodeWays, example_2)
{
    string s = "226";
    Solution obj;
    EXPECT_EQ(3, obj.numDecodings(s));
}

TEST(DecodeWays, example_3)
{
    string s = "06";
    Solution obj;
    EXPECT_EQ(0, obj.numDecodings(s));
}

TEST(DecodeWays, example_4)
{
    string s = "206";
    Solution obj;
    EXPECT_EQ(1, obj.numDecodings(s));
}

TEST(DecodeWays, example_5)
{
    string s = "260";
    Solution obj;
    EXPECT_EQ(0, obj.numDecodings(s));
}

TEST(DecodeWays, example_6)
{
    string s = "111111111111111111111111111111111111111111111";
    Solution obj;
    EXPECT_EQ(1836311903, obj.numDecodings(s));
}