#ifndef MY_SOLUTIONS_DP_H
#define MY_SOLUTIONS_DP_H

#include <vector>
#include <string>

namespace dp
{
    class Solution
    {
    public:
        // 332. Coin change
        int coinChange(std::vector<int> &coins, int amount);
        // extension of 300. longest increasing subsequence
        std::vector<int> pathOfLIS(std::vector<int> &nums);
        // 1143 longest common subsequence
        int longestCommonSubsequence(std::string text1, std::string text2);
    };
}

#endif