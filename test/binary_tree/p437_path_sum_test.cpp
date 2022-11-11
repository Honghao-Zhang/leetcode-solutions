#include "binary_tree/binary_tree.h"
#include <gtest/gtest.h>
using namespace binary_tree;

TEST(PathSum3, example_1)
{
    std::vector<std::string> inputs{"10", "5", "-3", "3", "2", "null", "11", "3", "-2", "null", "1"};
    TreeNode *root = createTreeFromStrArray(inputs);
    Solution obj;
    EXPECT_EQ(3, obj.pathSum3(root, 8));
}

TEST(PathSum3, example_2)
{
    std::vector<std::string> inputs{"5", "4", "8", "11", "null", "13", "4", "7", "2", "null", "null", "5", "1"};
    TreeNode *root = createTreeFromStrArray(inputs);
    Solution obj;
    EXPECT_EQ(3, obj.pathSum3(root, 22));
}