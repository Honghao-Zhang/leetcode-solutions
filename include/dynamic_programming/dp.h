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
        // low points
        int sizeOfBiggestLowArea(std::vector<std::vector<int>> matrix);
        // 279 perfect squares
        int numSquares(int n);
        // 438 find all anagrams in a string
        std::vector<int> findAnagrams(std::string s, std::string p);
    };
}

#endif