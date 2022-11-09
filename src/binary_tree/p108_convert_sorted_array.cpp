#include "binary_tree/binary_tree.h"

using namespace binary_tree;

TreeNode *generateNewNode(std::vector<int> &nums, int start, int end)
{
    if (start > end)
        return nullptr;
    int mid = (start + end) / 2;
    TreeNode *cur = new TreeNode(nums[mid]);
    cur->left = generateNewNode(nums, start, mid - 1);
    cur->right = generateNewNode(nums, mid + 1, end);
    return cur;
}

TreeNode *Solution::sortedArrayToBST(std::vector<int> &nums)
{
    return generateNewNode(nums, 0, nums.size() - 1);
}