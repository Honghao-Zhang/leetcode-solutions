#include "backtracking/backtracking.h"

using namespace std;
using namespace backtracking;
// solution explained in https://leetcode.wang/leetCode-52-N-QueensII.html
void backtrack(int &count, int row, const int n, vector<bool> &main_diagonal, vector<bool> &anti_diagonal, vector<bool> &vertical)
{
    if (row == n)
        count++;
    for (auto col = 0; col < n; col++)
    {
        if (vertical[col] || main_diagonal[row - col + n] || anti_diagonal[row + col])
            continue;
        vertical[col] = main_diagonal[row - col + n] = anti_diagonal[row + col] = true;
        backtrack(count, row + 1, n, main_diagonal, anti_diagonal, vertical);
        vertical[col] = main_diagonal[row - col + n] = anti_diagonal[row + col] = false;
    }
}

int Solution::totalNQueens(int n)
{
    int count = 0;
    vector<bool> vertical(n, false);
    vector<bool> main_diagonal(2 * n, false);
    vector<bool> anti_diagonal(2 * n, false);
    backtrack(count, 0, n, main_diagonal, anti_diagonal, vertical);
    return count;
}
