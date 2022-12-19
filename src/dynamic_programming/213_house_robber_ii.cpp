#include "dynamic_programming/dp.h"

using namespace std;
using namespace dp;

int Solution::rob(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return nums[0];
    vector<int> rob_first(n), no_rob_first(n);
    rob_first[0] = nums[0];
    rob_first[1] = nums[0];
    no_rob_first[0] = 0;
    no_rob_first[1] = nums[1];
    for (auto i = 2; i < n - 1; i++)
    {
        rob_first[i] = max(nums[i] + rob_first[i - 2], rob_first[i - 1]);
    }
    for (auto i = 2; i < n; i++)
    {
        no_rob_first[i] = max(nums[i] + no_rob_first[i - 2], no_rob_first[i - 1]);
    }
    return max(rob_first[n - 2], no_rob_first[n - 1]);
}