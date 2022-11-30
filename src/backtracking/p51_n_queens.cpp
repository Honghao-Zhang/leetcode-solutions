#include "backtracking/backtracking.h"

using namespace std;
using namespace backtracking;

void updateOccupancy(vector<vector<bool>> &occupied, int i, int j, int board_size)
{
    occupied[i][j] = true;
    // update occupied horizontal
    for (auto k = 0; k < board_size; k++)
        occupied[i][k] = true;
    // update occupied vertical
    for (auto k = 0; k < board_size; k++)
        occupied[k][j] = true;
    // update diagonal down right
    for (auto k = i + 1, p = j + 1; k < board_size && p < board_size; k++, p++)
        occupied[k][p] = true;
    // update diagonal up left
    for (auto k = i - 1, p = j - 1; k >= 0 && p >= 0; k--, p--)
        occupied[k][p] = true;
    // update diagonal down left
    for (auto k = i + 1, p = j - 1; k < board_size && p >= 0; k++, p--)
        occupied[k][p] = true;
    // update diagonal up right
    for (auto k = i - 1, p = j + 1; k >= 0 && p < board_size; k--, p++)
        occupied[k][p] = true;
}
// solution 1: update
void placeQueen(vector<vector<string>> &ans, vector<string> board, int i, int j, vector<vector<bool>> occupied, int num_queens)
{
    board[i][j] = 'Q';
    updateOccupancy(occupied, i, j, board.size());
    num_queens++;
    // max number of queens == board.size()
    if (num_queens == board.size())
    {
        ans.push_back(board);
        return;
    }
    if (i + 1 >= board.size())
        return;
    for (auto k = 0; k < board.at(i).size(); ++k)
    {
        if (occupied[i + 1][k])
            continue;
        placeQueen(ans, board, i + 1, k, occupied, num_queens);
    }
}

vector<vector<string>> solution_1(int n)
{
    vector<vector<string>> ans;
    for (auto j = 0; j < n; ++j)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<bool>> occupied(n, vector<bool>(n, false));
        placeQueen(ans, board, 0, j, occupied, 0);
    }
    return ans;
}
// solution 2
void placeQueenInRow(vector<vector<string>> &ans, vector<string> board, int i, vector<vector<bool>> occupied, int num_queens)
{
    // max number of queens == board.size()
    if (num_queens == board.size())
    {
        ans.push_back(board);
        return;
    }
    if (i >= board.size())
        return;
    for (auto j = 0; j < board.at(i).size(); ++j)
    {
        vector<string> cur_board(board);
        vector<vector<bool>> cur_occupied(occupied);
        if (cur_occupied[i][j])
            continue;

        cur_board[i][j] = 'Q';
        updateOccupancy(cur_occupied, i, j, cur_board.size());
        placeQueenInRow(ans, cur_board, i + 1, cur_occupied, num_queens + 1);
    }
}

vector<vector<string>> solution_2(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    vector<vector<bool>> occupied(n, vector<bool>(n, false));
    placeQueenInRow(ans, board, 0, occupied, 0);
    return ans;
}

// solution 3
bool isValid(const vector<string> &board, int row, int col)
{
    // vertical up
    for (auto k = 0; k < row; k++)
    {
        if (board[k][col] == 'Q')
            return false;
    }
    // diagonal up right
    for (auto i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    // diagonal up left
    for (auto i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void placeQueen(vector<vector<string>> &ans, vector<string> &board, int row)
{
    if (row == board.size())
        ans.push_back(board);
    for (auto col = 0; col < board.size(); col++)
    {
        if (isValid(board, row, col))
        {
            board[row][col] = 'Q';
            placeQueen(ans, board, row + 1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solution_3(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));
    placeQueen(ans, board, 0);
    return ans;
}

vector<vector<string>> Solution::solveNQueens(int n)
{
    return solution_3(n);
}