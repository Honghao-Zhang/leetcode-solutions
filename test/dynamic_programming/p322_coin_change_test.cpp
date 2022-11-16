#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace dp;

TEST(CoinChange, example_1)
{
    std::vector<int> coins{1, 2, 5, 10};
    int amount = 27;
    Solution obj;
    EXPECT_EQ(4, obj.coinChange(coins, amount));
}

TEST(CoinChange, example_2)
{
    std::vector<int> coins{216, 94, 15, 86};
    int amount = 5372;
    Solution obj;
    EXPECT_EQ(26, obj.coinChange(coins, amount));
}

TEST(CoinChange, example_3)
{
    std::vector<int> coins{1};
    int amount = 0;
    Solution obj;
    EXPECT_EQ(0, obj.coinChange(coins, amount));
}