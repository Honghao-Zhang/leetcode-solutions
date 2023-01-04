#include "backtracking/backtracking.h"
#include <gtest/gtest.h>
#include <unordered_map>
using namespace std;
using namespace backtracking;

TEST(GenerateParentheses, example_1)
{
    Solution obj;
    auto output = obj.generateParenthesis(3);
    unordered_map<string, int> expected;
    expected["((()))"] = 1;
    expected["(()())"] = 1;
    expected["(())()"] = 1;
    expected["()(())"] = 1;
    expected["()()()"] = 1;
    EXPECT_EQ(output.size(), expected.size());
    for (auto str : output)
    {
        EXPECT_EQ(expected[str], 1);
    }
}