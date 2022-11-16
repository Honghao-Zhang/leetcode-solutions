#include "dynamic_programming/dp.h"

using namespace dp;
using namespace std;

// solution 1: time limit exceeded on test example 2
// Time complexity O(amount * amount / 2) == O(amount^2)
int coinChange_1(vector<int> &coins, int amount)
{
    if (0 == amount)
        return 0;
    vector<int> tmp(amount + 1, -1);
    for (auto coin : coins)
    {
        if (coin == amount)
            return 1;
        else if (coin < amount)
            tmp[coin] = 1;
    }

    for (int idx = 2; idx <= amount; ++idx)
    {
        if (tmp[idx] == -1)
        {
            for (int amt = idx - 1; amt >= idx / 2 + idx % 2; amt--)
            {
                if (tmp[amt] != -1 && tmp[idx - amt] != -1)
                {
                    if (tmp[idx] != -1)
                    {
                        tmp[idx] = min(tmp[idx], tmp[amt] + tmp[idx - amt]);
                    }
                    else
                        tmp[idx] = tmp[amt] + tmp[idx - amt];
                }
            }
        }
    }
    return tmp[amount];
}
// solution 2: Time complxity O(amount * coins.size()), Space O(amount+1)
int coinChange_2(vector<int> &coins, int amount)
{
    // if (0 == amount)
    //     return 0;
    vector<int> tmp(amount + 1, amount + 1);
    tmp[0] = 0;
    for (int idx = 1; idx <= amount; ++idx)
    {
        for (auto coin : coins)
        {
            // if (coin == idx)
            //     tmp[idx] = 1;
            // else if (coin < idx)
            // {
            //     tmp[idx] = min(tmp[idx], tmp[idx - coin] + 1);
            // }
            if (coin <= idx)
                tmp[idx] = min(tmp[idx], tmp[idx - coin] + 1);
        }
    }
    return tmp[amount] > amount ? -1 : tmp[amount];
}

int Solution::coinChange(vector<int> &coins, int amount)
{
    return coinChange_2(coins, amount);
}