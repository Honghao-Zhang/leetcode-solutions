#include "matrix/matrix.h"

using namespace matrix;
// solution 1: dynamic programming
// time complexity: O(log(mn))
bool searchSubmatrix(std::vector<std::vector<int>> &matrix, int target, int start_row, int end_row, int start_col, int end_col)
{
    if (start_row > end_row || start_col > end_col)
        return false;
    if (start_row == end_row && start_col == end_col)
        return target == matrix[start_row][start_col];
    int mid_row = (start_row + end_row) / 2;
    int mid_col = (start_col + end_col) / 2;
    if (target < matrix[mid_row][mid_col])
    {
        // up right corner
        return searchSubmatrix(matrix, target, start_row, mid_row - 1, mid_col, end_col) ||
               // down left corner
               searchSubmatrix(matrix, target, mid_row, end_row, start_col, mid_col - 1) ||
               // up left corner
               searchSubmatrix(matrix, target, start_row, mid_row - 1, start_col, mid_col - 1);
    }
    else if (target > matrix[mid_row][mid_col])
    {
        // up right corner
        return searchSubmatrix(matrix, target, start_row, mid_row, mid_col + 1, end_col) ||
               // down left corner
               searchSubmatrix(matrix, target, mid_row + 1, end_row, start_col, mid_col) ||
               // down right corner
               searchSubmatrix(matrix, target, mid_row + 1, end_row, mid_col + 1, end_col);
    }
    else
        return true;
    return false;
}
// solution 2: use 2D coordinates
bool searchLinearFromUpRightCorner(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix.at(0).size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (target == matrix[i][j])
            return true;
        if (target < matrix[i][j])
            j--;
        else
            i++;
    }
    return false;
}

bool searchLinearFromDownLeftCorner(std::vector<std::vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix.at(0).size();
    int i = m - 1, j = 0;
    while (i >= 0 && j < n)
    {
        if (target == matrix[i][j])
            return true;
        if (target < matrix[i][j])
            i--;
        else
            j++;
    }
    return false;
}
// solution 3: diagonal search
// solution 4: row by row binary search
// solution 5: brute force
bool Solution::searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    // solution 1
    // return searchSubmatrix(matrix, target, 0, matrix.size() - 1, 0, matrix.at(0).size() - 1);
    // solution 2
    return searchLinearFromDownLeftCorner(matrix, target);
}