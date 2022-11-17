#include "array/array.h"
#include <climits>
using namespace std;
// solution 1: kadane algorithm, keep two current value (max, min) due to n < 0
int solution_1(vector<int> &nums)
{
    int max_so_far = INT_MIN;
    int cur_max_product = 1;
    int cur_min_product = 1;
    for (auto n : nums)
    {
        // no matter cur_max_product, cur_min_product are negative or positive
        // if n < 0, cur_max_product * n will result smaller than cur_min_product*n
        if (n < 0)
            swap(cur_max_product, cur_min_product);
        // when n == 0,
        cur_max_product = max(n, n * cur_max_product);
        cur_min_product = min(n, n * cur_min_product);
        max_so_far = max(max_so_far, max(cur_max_product, cur_min_product));
    }
    return max_so_far;
}

// solution 2: kadane algorithm
int solution_2(vector<int> &nums)
{
    int max_so_far = INT_MIN;
    int left2right = 0, right2left = 0;
    for (auto idx = 0; idx < nums.size(); idx++)
    {
        // if left2right == 0, then calculate new product by setting left2right = 1;
        left2right = (left2right ? left2right : 1) * nums[idx];
        // by nums=[-1, -2, -3] (the number of negative numbers in nums is odd),
        // left2right will not cover the product of (-2 * -3)
        right2left = (right2left ? right2left : 1) * nums[nums.size() - 1 - idx];
        max_so_far = max(max_so_far, max(left2right, right2left));
    }
    return max_so_far;
}

int my_array::maxProductSubarray(vector<int> &nums)
{
    return solution_2(nums);
}

// Kadane algorithm
int my_array::maxSumSubarray(vector<int> &nums)
{
    int max_so_far = INT_MIN;
    int max_ends_here = 0;
    for (auto n : nums)
    {
        max_ends_here = max_ends_here < 0 ? 0 : max_ends_here;
        max_ends_here += n;
        max_so_far = max(max_so_far, max_ends_here);
    }
    return max_so_far;
}

std::vector<int> my_array::findMaxSumSubarray(std::vector<int> &nums)
{
    int start_idx = 0, end_idx = 0;
    int max_so_far = INT_MIN;
    int max_ends_here = 0;
    for (auto idx = 0; idx < nums.size(); ++idx)
    {
        if (max_ends_here < 0)
        {
            max_ends_here = 0;
            start_idx = idx;
        }
        max_ends_here += nums[idx];
        if (max_ends_here > max_so_far)
        {
            max_so_far = max_ends_here;
            end_idx = idx;
        }
    }
    return std::vector<int>(nums.begin() + start_idx, nums.begin() + end_idx);
}