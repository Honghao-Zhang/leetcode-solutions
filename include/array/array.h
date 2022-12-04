#ifndef MY_SOLUTIONS_ARRAY_H
#define MY_SOLUTIONS_ARRAY_H
#include <vector>
namespace my_array
{
    // 152. maximum product subarray
    int maxProductSubarray(std::vector<int> &nums);
    int maxSumSubarray(std::vector<int> &nums);
    std::vector<int> findMaxSumSubarray(std::vector<int> &nums);
    // 189. rotate array
    void rotate(std::vector<int> &nums, int k);
    // 239. sliding window maximum
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k);
}
#endif