#ifndef MY_SOLUTIONS_DP_H
#define MY_SOLUTIONS_DP_H

#include <vector>

namespace dp
{
    class Solution
    {
    public:
        // 332. Coin change
        int coinChange(std::vector<int> &coins, int amount);
        // extension of 300. longest increasing subsequence
        std::vector<int> pathOfLIS(std::vector<int> &nums);
    };
}

#endif