#include "breadth_first_search/bfs.h"
using namespace std;
using namespace bfs;
// solution 1: (my solution) breadth first search
bool matchCharacter(char ch, vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited)
{
    if (i < 0 || i >= board.size() || j < 0 || j >= board.at(0).size())
        return false;
    if (visited[i][j])
        return false;
    if (ch == board[i][j])
    {
        visited[i][j] = true;
        return true;
    }
    else
        return false;
}

bool solution_1(std::vector<std::vector<char>> &board, string word)
{
    int m = board.size(), n = board.at(0).size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<pair<int, int>> start;
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (word[idx] == board[i][j])
                start.push_back({i, j});
        }
    }
    if (!start.empty())
    {
        for (auto p : start)
        {
            int cur_i = p.first, cur_j = p.second;
            visited = vector(m, vector<bool>(n, false));
            idx = 1;
            visited[cur_i][cur_j] = true;
            while (idx < word.size())
            {
                if (matchCharacter(word[idx], board, cur_i - 1, cur_j, visited))
                    cur_i = cur_i - 1;
                else if (matchCharacter(word[idx], board, cur_i + 1, cur_j, visited))
                    cur_i = cur_i + 1;
                else if (matchCharacter(word[idx], board, cur_i, cur_j + 1, visited))
                    cur_j = cur_j + 1;
                else if (matchCharacter(word[idx], board, cur_i, cur_j - 1, visited))
                    cur_j = cur_j - 1;
                else
                    break;
                idx++;
            }
            if (idx == word.size())
                return true;
        }
    }
    return false;
}

// solution 2: optimization of solution 1
bool matchWord(const string &word, int idx, vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited)
{
    if (idx == word.size())
        return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board.at(0).size() || visited[i][j] || word[idx] != board[i][j])
        return false;
    visited[i][j] = true;
    if (matchWord(word, idx + 1, board, i + 1, j, visited) || matchWord(word, idx + 1, board, i - 1, j, visited) || matchWord(word, idx + 1, board, i, j + 1, visited) || matchWord(word, idx + 1, board, i, j - 1, visited))
        return true;
    else
    {
        visited[i][j] = false;
        return false;
    }
}

bool solution_2(std::vector<std::vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.at(0).size(); ++j)
        {
            int idx = 0;
            vector<vector<bool>> visited(board.size(), vector<bool>(board.at(0).size(), false));
            if (matchWord(word, idx, board, i, j, visited))
                return true;
        }
    }
    return false;
}
// solution 3: optimisation of solution 2 by deprecating visited matrix
bool matchWord(const string &word, int idx, vector<vector<char>> &board, int i, int j)
{
    if (idx == word.size())
        return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board.at(0).size() || word[idx] != board[i][j])
        return false;
    board[i][j] = '?';
    bool res = matchWord(word, idx + 1, board, i + 1, j) 
            || matchWord(word, idx + 1, board, i - 1, j) 
            || matchWord(word, idx + 1, board, i, j + 1) 
            || matchWord(word, idx + 1, board, i, j - 1);
    board[i][j] = word[idx];
    return res;
}

bool solution_3(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board.at(0).size(); ++j)
        {
            if (matchWord(word, 0, board, i, j))
                return true;
        }
    }
    return false;
}

bool Solution::exist(std::vector<std::vector<char>> &board, string word)
{
    return solution_3(board, word);
}