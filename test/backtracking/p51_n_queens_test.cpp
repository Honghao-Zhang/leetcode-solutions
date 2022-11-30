#include "backtracking/backtracking.h"
#include <gtest/gtest.h>
using namespace std;
using namespace backtracking;

TEST(NQueens, example_1)
{
    for (auto i = -1; i >= 0; i++)
    {
        continue;
    }
    Solution obj;
    int n = 4;
    auto res = obj.solveNQueens(n);
    vector<vector<string>> expected{{".Q..", "...Q", "Q...", "..Q."}, {"..Q.", "Q...", "...Q", ".Q.."}};
    EXPECT_EQ(res.size(), expected.size());
    for (auto k = 0; k < res.size(); k++)
    {
        for (auto p = 0; p < res[k].size(); p++)
        {
            EXPECT_TRUE(res[k][p] == expected[k][p]);
        }
    }
}
