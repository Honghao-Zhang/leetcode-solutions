#ifndef MY_SOLUTIONS_DP_H
#define MY_SOLUTIONS_DP_H

#include <vector>
#include <string>

namespace dp
{
    struct Cell
    {
        int x, h;
        Cell(int xx, int hh) : x(xx), h(hh) {}
        bool operator<(const Cell &rhs) const
        {
            return this->h > rhs.h;
        }
    };
    struct Cell2D
    {
        int x, y, h;
        Cell2D(int xx, int yy, int hh) : x(xx), y(yy), h(hh) {}
        bool operator<(const Cell2D &rhs) const
        {
            return this->h > rhs.h;
        }
    };
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
        // 416 partition equal subset sum
        bool canPartition(std::vector<int> &nums);
        // 42 trapping rain water
        int trap(std::vector<int> &height);
        // 407 trapping rain water ii
        int trapRainWater(std::vector<std::vector<int>> &heightMap);
        // 213 house robber ii
        int rob(std::vector<int> &nums);
    };
}

#endif