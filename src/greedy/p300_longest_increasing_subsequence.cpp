#include "greedy/greedy.h"
#include <algorithm>
using namespace std;
using namespace greedy;
// solution 1: greedy, refer to doc/LongestIncreasingSubsequence.pdf
int solution_1(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;
    vector<int> dp;
    dp.push_back(nums.at(0));
    for (auto i = 1; i < nums.size(); i++)
    {
        bool flag = false;
        for (auto j = 0; j < dp.size(); j++)
        {
            if (nums[i] <= dp[j])
            {
                dp[j] = nums[i];
                flag = true;
                break;
            }
        }
        if (!flag)
            dp.push_back(nums[i]);
    }
    return dp.size();
}

// solution 2: brute force,
// not work for example [0, 1, 0, 3, 2, 3], the first 3 will always block first 2 from being pushed into vector
int solution_2_not_work(vector<int> &nums)
{
    vector<vector<int>> all;
    vector<int> tmp;
    int length = 0;
    for (auto i = 0; i < nums.size() - 1; i++)
    {
        // current sequence starts with nums[i]
        tmp.push_back(nums[i]);
        for (auto j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > tmp.back())
                tmp.push_back(nums[j]);
        }
        if (tmp.size() >= length)
        {
            while (!all.empty() && all.back().size() < tmp.size())
                all.pop_back();
            all.push_back(tmp);
            length = tmp.size();
        }
        tmp.clear();
    }
    return length;
}

// solution 2: dynamic programming
int solution_2(vector<int> &nums)
{
    int n = nums.size();
    int max_len = 0;
    vector<int> lengthes(n, 1);
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                lengthes[i] = max(lengthes[i], lengthes[j] + 1);
            }
        }
        max_len = max(lengthes[i], max_len);
    }
    return max_len;
    // return *max_element(lengthes.begin(), lengthes.end());
}

// solution 3: monotonic queue,
// not work for example [0, 1, 0, 3, 2, 3], the second 0 will always flush interval [0, 1] in the queue
int solution_3(vector<int> &nums)
{
    vector<int> indices;
    size_t length = 0;
    for (auto idx = 0; idx < nums.size(); idx++)
    {
        while (!indices.empty() && nums[idx] <= nums[indices.back()])
        {
            indices.pop_back();
        }
        indices.push_back(idx);
        length = max(length, indices.size());
    }
    return length;
}

int Solution::lengthOfLIS(std::vector<int> &nums)
{
    return solution_2(nums);
}