#include "substring/substring.h"
#include <gtest/gtest.h>
using namespace std;
using namespace substring;

TEST(WordBreak, example_1)
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution obj;
    EXPECT_TRUE(obj.wordBreak(s, wordDict));
}

TEST(WordBreak, example_2)
{
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaa", "aaaa"};
    Solution obj;
    EXPECT_TRUE(obj.wordBreak(s, wordDict));
}

TEST(WordBreak, example_3)
{
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution obj;
    EXPECT_FALSE(obj.wordBreak(s, wordDict));
}

TEST(WordBreak, example_4)
{
    string s = "a";
    vector<string> wordDict = {"a"};
    Solution obj;
    EXPECT_TRUE(obj.wordBreak(s, wordDict));
}