#include "binary_tree/binary_tree.h"
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
using namespace binary_tree;
// my solution: use reverse function
vector<vector<int>> solution_1(TreeNode *root)
{
    int cur_level = 0;
    queue<pair<TreeNode *, int>> myQueue;
    vector<vector<int>> ans;
    vector<int> cur_vec;
    if (!root)
        // return ans;
        return {}; // this is c++11 feature, would reture an object of the fuction's return type initialized with an empty list initializer.
    myQueue.push({root, 0});
    while (!myQueue.empty())
    {
        auto cur_element = myQueue.front();
        myQueue.pop();
        if (cur_element.first->left)
            myQueue.push({cur_element.first->left, cur_element.second + 1});
        if (cur_element.first->right)
            myQueue.push({cur_element.first->right, cur_element.second + 1});
        if (cur_level != cur_element.second)
        {
            if (!cur_vec.empty())
            {
                if (cur_level % 2 == 1)
                {
                    reverse(cur_vec.begin(), cur_vec.end());
                }
                ans.push_back(cur_vec);
                cur_vec.clear();
            }
            cur_level++;
        }
        cur_vec.push_back(cur_element.first->val);
    }
    if (!cur_vec.empty())
    {
        if (cur_level % 2 == 1)
        {
            reverse(cur_vec.begin(), cur_vec.end());
        }
        ans.push_back(cur_vec);
        cur_vec.clear();
    }
    return ans;
}

// solution 2: use size of each level for reverse
vector<vector<int>> solution_2(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> tmp;
    bool left_to_right = true;
    tmp.push(root);
    while (!tmp.empty())
    {
        int level_size = tmp.size();
        vector<int> cur_level(level_size);
        for (int i = 0; i < level_size; i++)
        {
            auto cur_node = tmp.front();
            tmp.pop();
            int idx = left_to_right ? i : level_size - 1 - i;
            cur_level[idx] = cur_node->val;
            if (cur_node->left)
                tmp.push(cur_node->left);
            if (cur_node->right)
                tmp.push(cur_node->right);
        }
        left_to_right = !left_to_right;
        ans.push_back(cur_level);
    }
    return ans;
}

// solution 3: use two stack
vector<vector<int>> solution_3(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    stack<TreeNode *> s1, s2;
    s1.push(root);
    vector<int> level;
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            TreeNode *node = s1.top();
            s1.pop();
            level.push_back(node->val);
            if (node->left)
                s2.push(node->left);
            if (node->right)
                s2.push(node->right);
        }
        if (!level.empty())
        {
            ans.push_back(level);
            level.clear();
        }
        while (!s2.empty())
        {
            TreeNode *node = s2.top();
            s2.pop();
            level.push_back(node->val);
            if (node->right)
                s1.push(node->right);
            if (node->left)
                s1.push(node->left);
        }
        if (!level.empty())
        {
            ans.push_back(level);
            level.clear();
        }
    }
    return ans;
}
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode *root)
{
    return solution_3(root);
}