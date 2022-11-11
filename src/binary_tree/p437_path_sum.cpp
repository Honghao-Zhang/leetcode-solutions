#include "binary_tree/binary_tree.h"
#include <unordered_map>
#include <queue>
using namespace binary_tree;
using namespace std;
// Solution 1: dynamic programming for calculating sum on specified node, traversal on entire tree
// Time complexity: O(n^2)
void calculateSumBelow(TreeNode *node, int &cnt, int tgt)
{
    if (!node)
        return;
    int new_tgt = tgt - node->val;
    if (new_tgt == 0)
        cnt++;
    calculateSumBelow(node->left, cnt, new_tgt);
    calculateSumBelow(node->right, cnt, new_tgt);
}

int pathSum3_solution1(TreeNode *root, int target)
{
    int cnt = 0;
    if (!root)
        return cnt;
    queue<TreeNode *> tmp;
    tmp.push(root);
    while (!tmp.empty())
    {
        calculateSumBelow(tmp.front(), cnt, target);
        if (tmp.front()->left)
            tmp.push(tmp.front()->left);
        if (tmp.front()->right)
            tmp.push(tmp.front()->right);
        tmp.pop();
    }
    return cnt;
}

// Solution 2: use hashmap to store temporary sums in current path
void calculateSumInPath(TreeNode *node, unordered_map<long, int> &sum_map, int &cnt, int tgt, int cur_sum)
{
    if (!node)
        return;
    cur_sum += node->val;
    if (cur_sum == tgt)
        cnt++;
    if (sum_map.find(cur_sum - tgt) != sum_map.end())
        cnt += sum_map[cur_sum - tgt];
    sum_map[cur_sum]++;
    calculateSumInPath(node->left, sum_map, cnt, tgt, cur_sum);
    calculateSumInPath(node->right, sum_map, cnt, tgt, cur_sum);
    sum_map[cur_sum]--; // current path terminates, clear the sum
}

int pathSum3_solution2(TreeNode *root, int targetSum)
{
    unordered_map<long, int> sum_map;
    int cnt = 0;
    calculateSumInPath(root, sum_map, cnt, targetSum, 0);
    return cnt;
}

int Solution::pathSum3(TreeNode *root, int targetSum)
{
    return pathSum3_solution2(root, targetSum);
}