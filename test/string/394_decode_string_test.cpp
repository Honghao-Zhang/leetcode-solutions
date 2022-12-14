#include "string/string.h"
#include <gtest/gtest.h>
using namespace std;
using namespace my_string;

// TEST(DecodeString, example_1)
// {
//     string s{"3[a]2[bc]"};
//     string expected{"aaabcbc"};
//     Solution obj;
//     string output = obj.decodeString(s);
//     EXPECT_TRUE(expected == output);
// }

TEST(DecodeString, example_2)
{
    string s{"3[a2[c]]"};
    string expected{"accaccacc"};
    Solution obj;
    string output = obj.decodeString(s);
    EXPECT_TRUE(expected == output);
}

TEST(DecodeString, example_3)
{
    string s{"cd2[abc]3[cd]ef"};
    string expected{"abcabccdcdcdef"};
    Solution obj;
    string output = obj.decodeString(s);
    EXPECT_TRUE(expected == output);
}