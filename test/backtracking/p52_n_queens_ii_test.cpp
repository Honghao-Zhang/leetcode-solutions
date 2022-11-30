#include "backtracking/backtracking.h"
#include <gtest/gtest.h>
using namespace std;
using namespace backtracking;

TEST(NQueensII, example_1)
{
    Solution obj;
    EXPECT_EQ(2, obj.totalNQueens(4));
}
