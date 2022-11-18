#include "hash/hash.h"
#include <gtest/gtest.h>

TEST(PartitionLabels, example_1)
{
    std::string s = "ababcbacadefegdehijhklij";
    auto res = my_hash::partitionLabels(s);
    std::vector<int> expected_res{9, 7, 8};
    EXPECT_EQ(res.size(), expected_res.size());
    for (auto idx = 0; idx < res.size(); idx++)
    {
        EXPECT_EQ(res[idx], expected_res[idx]);
    }
}