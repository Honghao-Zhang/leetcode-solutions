#ifndef MY_SOLUTIONS_BINARY_TREE_H
#define MY_SOLUTIONS_BINARY_TREE_H

#include <vector>

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

    class Solution
    {
    public:
        // 108. Convert Sorted Array to Binary Search Tree
        TreeNode *sortedArrayToBST(std::vector<int> &nums);
    };
};

#endif