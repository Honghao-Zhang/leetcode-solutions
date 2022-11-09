#include "matrix/matrix.h"
#include <gtest/gtest.h>
using namespace matrix;

TEST(Search2DMatrix, example_1)
{
    std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
    int target = 5;
    Solution obj;
    EXPECT_TRUE(obj.searchMatrix(matrix, target));
}

TEST(Search2DMatrix, example_2)
{
    std::vector<std::vector<int>> matrix{{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
    int target = 20;
    Solution obj;
    EXPECT_FALSE(obj.searchMatrix(matrix, target));
}