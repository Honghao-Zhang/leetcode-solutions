#include "array/array.h"
#include <queue>
using namespace std;
using namespace my_array;

vector<int> solution_1(vector<int> &nums, int k)
{
    vector<int> ans;
    int l = 0, r = 0;
    int cur_max = nums.at(0);
    while (r <= nums.size())
    {
        if (r - l < k)
        {
            // sliding window does not have enough numbers
            cur_max = max(cur_max, nums[r]);
            r++;
        }
        else
        {
            ans.push_back(cur_max);
            if (nums[r] >= cur_max)
            {
                l++;
            }
            else
            {
                if (nums[l] == cur_max)
                {
                    priority_queue<int> tmp(nums.begin() + l + 1, nums.begin() + r);
                    cur_max = tmp.top();
                }
                else
                {
                    l++;
                }
            }
        }
    }
    return ans;
}
// solution 2: monotonic queue-> a queue the elements from the front to the end is stictly either increasing or decreasing
// https://medium.com/algorithms-and-leetcode/monotonic-queue-explained-with-leetcode-problems-7db7c530c1d6
vector<int> solution_2(vector<int> &nums, int k)
{
    deque<int> indices;
    vector<int> ans;
    for (auto i = 0; i < nums.size(); ++i)
    {
        if(!indices.empty() && indices.front() == i-k)
            indices.pop_front();
        while (!indices.empty() && nums[indices.back()] < nums[i])
            indices.pop_back();
        indices.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[indices.front()]);
    }
    return ans;
}

std::vector<int> my_array::maxSlidingWindow(std::vector<int> &nums, int k)
{
    return solution_2(nums, k);
}