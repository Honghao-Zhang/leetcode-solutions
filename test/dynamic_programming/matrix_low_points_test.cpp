#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;

TEST(MatrixLowPoints, example_1)
{
    vector<vector<int>> matrix{{0, 1, 2, 3, 5}, {2, 3, 4, 6, 9}, {5, 6, 7, 3, 4}, {7, 8, 1, 2, 3}, {9, 5, 3, 4, 1}};
    Solution obj;
    EXPECT_EQ(10, obj.sizeOfBiggestLowArea(matrix));
}