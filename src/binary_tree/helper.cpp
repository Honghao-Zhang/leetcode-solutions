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

binary_tree::TreeNode *createTree(std::vector<std::string> &strArry, int idx)
{
    if (idx >= strArry.size() || idx < 0)
        return nullptr;
    if (strArry.at(idx) == "null")
        return nullptr;
    binary_tree::TreeNode *cur = new binary_tree::TreeNode(std::stoi(strArry.at(idx)));
    cur->left = createTree(strArry, 2 * idx + 1);
    cur->right = createTree(strArry, 2 * idx + 2);
    return cur;
}

binary_tree::TreeNode *binary_tree::createTreeFromStrArray(std::vector<std::string> strArry)
{
    if (strArry.empty())
        return nullptr;
    return createTree(strArry, 0);
}