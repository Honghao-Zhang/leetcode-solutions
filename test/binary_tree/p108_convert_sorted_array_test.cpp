#include "binary_tree/binary_tree.h"
#include <gtest/gtest.h>
using namespace binary_tree;

TEST(ConvertSortedArry2BST, example_1)
{
    std::vector<int> nums{-10, -3, 0, 5, 9};
    Solution obj;
    auto tree = obj.sortedArrayToBST(nums);
    std::vector<int> res = breadthFirstTraversal(tree);
    std::vector<int> expected_res{0, -10, 5, -3, 9};
    EXPECT_EQ(res.size(), expected_res.size());
    for (auto idx = 0; idx < res.size(); ++idx)
        EXPECT_EQ(expected_res.at(idx), res.at(idx));
}

TEST(ConvertSortedArry2BST, example_2)
{
    std::vector<int> nums{1, 3};
    Solution obj;
    auto tree = obj.sortedArrayToBST(nums);
    std::vector<int> res = breadthFirstTraversal(tree);
    std::vector<int> expected_res{1, 3};
    EXPECT_EQ(res.size(), expected_res.size());
    for (auto idx = 0; idx < res.size(); ++idx)
        EXPECT_EQ(expected_res.at(idx), res.at(idx));
}