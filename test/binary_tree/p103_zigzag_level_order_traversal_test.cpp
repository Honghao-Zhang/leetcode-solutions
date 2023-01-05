#include "binary_tree/binary_tree.h"
#include <gtest/gtest.h>
using namespace std;
using namespace binary_tree;

TEST(ZigZagTraversal, example_1)
{
    TreeNode *root = binary_tree::createTreeFromStrArray({"3",
                                                          "9",
                                                          "20",
                                                          "null",
                                                          "null",
                                                          "15",
                                                          "7"});
    Solution obj;
    vector<vector<int>> expected{{3}, {20, 9}, {15, 7}};
    auto output = obj.zigzagLevelOrder(root);
    EXPECT_EQ(output.size(), expected.size());
    for (int i = 0; i < expected.size(); i++)
    {
        for (int j = 0; j < expected[i].size(); j++)
        {
            EXPECT_EQ(output[i][j], expected[i][j]);
        }
    }
}