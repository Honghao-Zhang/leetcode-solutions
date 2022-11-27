#include "dynamic_programming/dp.h"
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
using namespace dp;

vector<pair<int, int>> findLowPoints(const vector<vector<int>> &matrix)
{
    vector<pair<int, int>> ans;
    int m = matrix.size(), n = matrix.at(0).size();
    for (auto i = 0; i < m; i++)
    {
        for (auto j = 0; j < n; j++)
        {
            if (i > 0 && matrix[i][j] >= matrix[i - 1][j])
                continue;
            if (i < m - 1 && matrix[i][j] >= matrix[i + 1][j])
                continue;
            if (j > 0 && matrix[i][j] >= matrix[i][j - 1])
                continue;
            if (j < n - 1 && matrix[i][j] >= matrix[i][j + 1])
                continue;
            ans.push_back({i, j});
        }
    }
    return ans;
}

using Point = pair<int, int>;
// struct Compare_pair_second
// {
//     bool operator()(const pair<int, int> &a, const pair<int, int> &b)
//     {
//         return a.second < b.second;
//     }
// };
// using AreaQueue = priority_queue<pair<int, int>, vector<pair<int, int>>, Compare_pair_second>;

void visitPoint(const vector<vector<int>> &matrix, vector<vector<int>> &visited, unordered_map<int, int> &areas, Point cur, int low_point_idx)
{
    int &cur_i = cur.first, &cur_j = cur.second;
    if (visited[cur_i][cur_j] != 0)
    {
        if (visited[cur_i][cur_j] != low_point_idx)
        {
            areas[visited[cur_i][cur_j]]--;
            visited[cur_i][cur_j] = -1;
        }
        return;
    }
    visited[cur_i][cur_j] = low_point_idx;
    areas[low_point_idx]++;

    if (cur_i > 0 && matrix[cur_i - 1][cur_j] > matrix[cur_i][cur_j])
        visitPoint(matrix, visited, areas, {cur_i - 1, cur_j}, low_point_idx);

    if (cur_i < matrix.size() - 1 && matrix[cur_i + 1][cur_j] > matrix[cur_i][cur_j])
        visitPoint(matrix, visited, areas, {cur_i + 1, cur_j}, low_point_idx);

    if (cur_j > 0 && matrix[cur_i][cur_j - 1] > matrix[cur_i][cur_j])
        visitPoint(matrix, visited, areas, {cur_i, cur_j - 1}, low_point_idx);

    if (cur_i < matrix.at(0).size() - 1 && matrix[cur_i][cur_j + 1] > matrix[cur_i][cur_j])
        visitPoint(matrix, visited, areas, {cur_i, cur_j + 1}, low_point_idx);
}

int findBiggestLowArea(const vector<vector<int>> &matrix, const vector<pair<int, int>> &low_points)
{
    int m = matrix.size(), n = matrix.at(0).size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    unordered_map<int, int> areas;
    for (auto k = 0; k < low_points.size(); ++k)
    {
        areas[k + 1] = -1;
        visitPoint(matrix, visited, areas, low_points[k], k + 1);
    }
    for (auto r : visited)
    {
        for (auto c : r)
        {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
    int biggest_area = 0;
    for (auto a : areas)
        biggest_area = max(a.second, biggest_area);
    return biggest_area;
}

int Solution::sizeOfBiggestLowArea(vector<vector<int>> matrix)
{
    auto low_pnts = findLowPoints(matrix);
    return findBiggestLowArea(matrix, low_pnts);
}
