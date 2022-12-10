#include "dynamic_programming/dp.h"
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;
using namespace dp;

// Solution 1: this will not work for test example 4, because the elements building the subarray could be not consecutive
bool help_not_work(const vector<int> &sums, const int half, uint8_t l, uint8_t r)
{
    if (l >= r || r == sums.size())
        return false;
    int cur_sum = sums[r] - sums[l];
    if (cur_sum == half)
        return true;
    if (cur_sum < half)
        return help_not_work(sums, half, l, r + 1);
    else
        return help_not_work(sums, half, l + 1, r);
}

bool solution_1_not_work(vector<int> &nums)
{
    uint8_t len = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> sums(len + 1);
    sums[0] = 0;
    for (auto idx = 1; idx <= len; idx++)
    {
        sums[idx] = nums[idx - 1] + sums[idx - 1];
    }
    if (sums.back() % 2 == 1)
        return false;
    int half = sums.back() / 2;
    uint8_t l = 0, r = 1;
    return help_not_work(sums, half, l, r);
}
// Solution 1: this approach uses dynamic programming,
// works for short inputs, but result in Time Limit Exceeded with larget inputs
bool help(const vector<int> &nums, int idx, const int target)
{
    if (idx < 0)
        return false;
    if (nums[idx] == target)
        return true;
    if (nums[idx] > target)
        return help(nums, idx - 1, target);
    else
        return help(nums, idx - 1, target - nums[idx]) || help(nums, idx - 1, target);
}

bool solution_1(const vector<int> &nums)
{
    int len = nums.size();
    int sum = 0;
    for (auto n : nums)
        sum += n;
    if (sum % 2 == 1)
        return false;
    int half = sum / 2;
    // knappsack problem: find a subarray whose sum is half
    return help(nums, len - 1, half);
}

// solution 2: bottom-up the dp approach
// this already works for large inputs
bool solution_2(const vector<int> &nums)
{
    int len = nums.size();
    int sum = 0;
    for (auto n : nums)
        sum += n;
    if (sum % 2 == 1)
        return false;
    int half = sum / 2;
    // matrix records whether a sum [0, 1, 2,...,half] can be formed by
    // adding elements from nums [0, nums.front(), ... nums.back()]
    // this 0 indicates no element will be used
    vector<vector<bool>> matrix(len + 1, vector<bool>(half + 1, false));
    for (auto i = 0; i <= len; i++)
    {
        // the first column is always true, because a sum 0 can always be reached by adding nothing from nums
        matrix[i][0] = true;
    }

    // for (auto j = 1; j <= half; j++)
    // {
    //   // this means, with "element 0" (nothing from nums), none of the sums can be reached except 0
    //     matrix[0][j] = false;
    // }
    for (auto i = 1; i <= len; i++)
    {
        for (auto j = 1; j <= half; j++)
        {
            if (j >= nums[i - 1])
                matrix[i][j] = matrix[i - 1][j - nums[i - 1]] || matrix[i - 1][j];
            else
                matrix[i][j] = matrix[i - 1][j];
        }
    }
    return matrix[len][half];
}

// solution 2.1 memory optimization
bool solution_2_1(const vector<int> &nums)
{
    int len = nums.size();
    int sum = 0;
    for (auto n : nums)
        sum += n;
    if (sum % 2 == 1)
        return false;
    int half = sum / 2;
    vector<bool> matches(half + 1, false);
    matches[0] = true;
    for (auto i = 1; i <= len; i++)
    {
        // for (auto j = 1; j <= half; j++)
        for (auto j = half; j >= 1; j--)
        {
            if (j >= nums[i - 1])
                matches[j] = matches[j - nums[i - 1]] || matches[j];
        }
    }
    return matches.back();
}
// solution 3: bit operation
bool solution_3(const vector<int> &nums)
{
    int len = nums.size();
    int sum = 0;
    for (auto n : nums)
        sum += n;
    if (sum % 2 == 1)
        return false;
    int half = sum / 2;
    bitset<40> matches;
    matches[0] = 1; // set the lowest bit
    // std::cout << "before is: " << matches.to_ulong() << std::endl;
    for (auto n : nums)
    {
        matches |= matches << n; // << makes the value bigger
        std::cout << "num is: " << matches.to_string() << std::endl;
    }

    return matches[half];
}
bool Solution::canPartition(vector<int> &nums)
{
    return solution_3(nums);
}
// TODO: bit indexed tree, element tree