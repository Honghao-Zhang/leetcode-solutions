#include "binary_tree/binary_tree.h"
#include <queue>

// namespace should be explictly added before function name
// otherwise an error with "undefined reference" will raised by linker
std::vector<int> binary_tree::breadthFirstTraversal(TreeNode *root)
{
    std::vector<int> results;
    if (!root)
        return results;
    std::queue<TreeNode *> tmp;
    tmp.push(root);
    while (!tmp.empty())
    {
        TreeNode *cur = tmp.front();
        results.push_back(cur->val);
        tmp.pop();
        if (cur->left)
            tmp.push(cur->left);
        if (cur->right)
            tmp.push(cur->right);
    }
    return results;
}