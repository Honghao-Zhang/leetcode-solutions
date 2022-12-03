#include "backtracking/backtracking.h"
#include <gtest/gtest.h>
using namespace std;
using namespace backtracking;

TEST(PalindromePartition, example_1)
{
    Solution obj;
    string s{"aab"};
    vector<vector<string>> expected{{"a", "a", "b"}, {"aa", "b"}};
    auto out = obj.partition(s);
    EXPECT_TRUE(out.size() == expected.size());
    for (auto i = 0; i < out.size(); i++)
    {
        EXPECT_EQ(out[i].size(), expected[i].size());
        for (auto j = 0; j < out[i].size(); j++)
        {
            EXPECT_TRUE(out[i][j] == expected[i][j]);
        }
    }
}

TEST(PalindromePartition, example_2)
{
    Solution obj;
    string s{"a"};
    vector<vector<string>> expected{{"a"}};
    auto out = obj.partition(s);
    EXPECT_TRUE(out.size() == expected.size());
    for (auto i = 0; i < out.size(); i++)
    {
        EXPECT_EQ(out[i].size(), expected[i].size());
        for (auto j = 0; j < out[i].size(); j++)
        {
            EXPECT_TRUE(out[i][j] == expected[i][j]);
        }
    }
}