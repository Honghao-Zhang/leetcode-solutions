#include "dynamic_programming/dp.h"
#include <queue>
using namespace std;
using namespace dp;

int solution_1(vector<int> &height)
{
    int n = height.size();
    vector<pair<int, int>> border(n);
    int max_left = 0, max_right = 0;
    for (auto i = 0; i < n; i++)
    {
        if (height[i] < max_left)
        {
            border[i].first = max_left;
        }
        else
        {
            max_left = height[i];
            border[i].first = height[i];
        }
    }

    for (auto i = n - 1; i >= 0; i--)
    {
        if (height[i] < max_right)
        {
            border[i].second = max_right;
        }
        else
        {
            max_right = height[i];
            border[i].second = max_right;
        }
    }
    int ans = 0;
    for (auto i = 0; i < n; i++)
    {
        if (border[i].first > height[i] && border[i].second > height[i])
        {
            ans += min(border[i].first, border[i].second) - height[i];
        }
        const int n = height.size();
        if (n == 0)
            return 0;

        priority_queue<Cell> que;
        vector<bool> visited(n, false);
        // enque leftmost & rightmost cell
        que.push(Cell(0, height[0]));
        que.push(Cell(n - 1, height[n - 1]));
        visited[0] = true;
        visited[n - 1] = true;

        int water = 0;
        vector<int> xs({1, -1}); // right, left
        while (!que.empty())
        {
            Cell cell = que.top();
            que.pop();
            for (int inc : xs)
            {
                int xx = cell.x + inc;
                if (xx < 0 || xx >= n || visited[xx])
                    continue;
                water += max(0, cell.h - height[xx]);
                que.push(Cell(xx, max(cell.h, height[xx])));
                visited[xx] = true;
            }
        }
        return water;
    }
    return ans;
}

int solution_2(vector<int> &height)
{
    const int n = height.size();
    if (n == 0)
        return 0;

    priority_queue<Cell> que;
    vector<bool> visited(n, false);
    // enque leftmost & rightmost cell
    que.push(Cell(0, height[0]));
    que.push(Cell(n - 1, height[n - 1]));
    visited[0] = true;
    visited[n - 1] = true;

    int water = 0;
    vector<int> xs({1, -1}); // right, left
    while (!que.empty())
    {
        Cell cell = que.top();
        que.pop();
        for (int inc : xs)
        {
            int xx = cell.x + inc;
            if (xx < 0 || xx >= n || visited[xx])
                continue;
            water += max(0, cell.h - height[xx]);
            que.push(Cell(xx, max(cell.h, height[xx])));
            visited[xx] = true;
        }
    }
    return water;
}
int Solution::trap(vector<int> &height)
{
    return solution_2(height);
}