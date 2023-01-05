#ifndef MY_SOLUTIONS_BINARY_TREE_H
#define MY_SOLUTIONS_BINARY_TREE_H

#include <vector>
#include <string>

namespace binary_tree
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    std::vector<int> breadthFirstTraversal(TreeNode *root);
    // This function creates a binary tree from inputs like [10,5,-3,3,2,null,11,3,-2,null,1]
    TreeNode *createTreeFromStrArray(std::vector<std::string> strArry);

    class Solution
    {
    public:
        // 108. Convert Sorted Array to Binary Search Tree
        TreeNode *sortedArrayToBST(std::vector<int> &nums);
        // 437. Path Sum III
        int pathSum3(TreeNode *root, int targetSum);
        // 103 binary tree zigzag level order traversal
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root);
    };
};

#endif