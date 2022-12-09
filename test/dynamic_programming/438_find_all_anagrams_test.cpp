#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(FindAllAnagrams, example_1)
{
    string s{"cbaebabacd"}, p{"abc"};
    Solution obj;
    auto res = obj.findAnagrams(s, p);
    vector<int> expected{0, 6};
    EXPECT_TRUE(res == expected);
    // EXPECT_EQ(res.size(), expected.size());
    // for (auto idx = 0; idx < res.size(); idx++)
    // {
    //     EXPECT_EQ(res[idx], expected[idx]);
    // }
}

TEST(FindAllAnagrams, example_2)
{
    string s{"abab"}, p{"ab"};
    Solution obj;
    auto res = obj.findAnagrams(s, p);
    vector<int> expected{0, 1, 2};
    EXPECT_EQ(res.size(), expected.size());
    for (auto idx = 0; idx < res.size(); idx++)
    {
        EXPECT_EQ(res[idx], expected[idx]);
    }
}