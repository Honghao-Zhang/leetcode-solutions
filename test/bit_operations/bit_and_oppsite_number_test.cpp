#include "bit_operations/bit_operations.h"
#include <gtest/gtest.h>
#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
using namespace bit_operations;

TEST(BitAndOpposite, example_1)
{
    int n = 7;
    vector<int> expected{1, 2, 4};
    Solution obj;
    auto res = obj.powerTwoSum(n);
    EXPECT_EQ(expected.size(), res.size());
    for (auto idx = 0; idx < res.size(); ++idx)
    {
        EXPECT_EQ(expected[idx], res[idx]);
    }
}

TEST(BitAndOpposite, example_2)
{
    int n = 22;
    vector<int> expected;
    //{2, 4, 16};
    bitset<8> m(n);
    for (auto idx = 0; idx < m.size(); ++idx)
    {
        if (m[idx])
        {
            expected.push_back(pow(2, idx));
        }
    }
    Solution obj;
    auto res = obj.powerTwoSum(n);
    EXPECT_EQ(expected.size(), res.size());
    for (auto idx = 0; idx < res.size(); ++idx)
    {
        EXPECT_EQ(expected[idx], res[idx]);
    }
}

TEST(TestForFun, binary_storage)
{
    std::cout << "binary of  2 is:" << bitset<8>(2) << std::endl;
    std::cout << "binary of -2 is:" << bitset<8>(-2) << std::endl;
    int8_t a = 11;
    int8_t b = ~a + 1;
    int8_t c = -a;
    int8_t d = a & -a;
    int8_t e = a - d;
    e &= -e;
    int8_t f = a - d - e;
    f &= -f;
    std::cout << "binary of  a is:" << bitset<8>(a) << std::endl;
    std::cout << "binary of  b is:" << bitset<8>(b) << std::endl;
    std::cout << "binary of  c is:" << bitset<8>(c) << std::endl;
    std::cout << "binary of  d is:" << bitset<8>(d) << std::endl;
    std::cout << "binary of  e is:" << bitset<8>(e) << std::endl;
    std::cout << "binary of  f is:" << bitset<8>(f) << std::endl;
}