#include "breadth_first_search/bfs.h"
#include <queue>
#include <utility>

using namespace bfs;

int Solution::orangesRotting(vector<vector<int>> &grids)
{
    size_t rows = grids.size();
    size_t cols = grids.at(0).size();
    queue<pair<int, int>> rotten;
    int minutes = 0;
    int fresh = 0;
    for (auto i = 0; i < rows; ++i)
    {
        for (auto j = 0; j < cols; ++j)
        {
            switch (grids[i][j])
            {
            case 2:
                rotten.push({i, j});
                break;
            case 1:
                fresh++;
                break;
            default:
                break;
            }
        }
    }
    if (0 == fresh)
        return 0;
    if (rotten.empty())
        return -1;
    while (!rotten.empty() && fresh > 0)
    {
        size_t cur_rotten = rotten.size();
        for (auto idx = 0; idx < cur_rotten; ++idx)
        {
            int i = rotten.front().first;
            int j = rotten.front().second;
            rotten.pop();
            if (i - 1 >= 0 && grids[i - 1][j] == 1)
            {
                grids[i - 1][j] = 2;
                fresh--;
                rotten.push({i - 1, j});
            }
            if (i + 1 < rows && grids[i + 1][j] == 1)
            {
                grids[i + 1][j] = 2;
                fresh--;
                rotten.push({i + 1, j});
            }
            if (j - 1 >= 0 && grids[i][j - 1] == 1)
            {
                grids[i][j - 1] = 2;
                fresh--;
                rotten.push({i, j - 1});
            }
            if (j + 1 < cols && grids[i][j + 1] == 1)
            {
                grids[i][j + 1] = 2;
                fresh--;
                rotten.push({i, j + 1});
            }
        }
        minutes++;
    }
    if (fresh > 0)
        return -1;
    return minutes;
}