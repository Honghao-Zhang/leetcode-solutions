#include "backtracking/backtracking.h"

using namespace std;
using namespace backtracking;

bool isPalindrome(const string &s, int l, int r)
{
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

void backtrack(vector<vector<string>> &ans, vector<string> &splits, const string &s, int start_pos)
{
    if (start_pos == s.size())
        ans.push_back(splits);
    for (auto end_pos = start_pos; end_pos < s.size(); end_pos++)
    {
        if (isPalindrome(s, start_pos, end_pos))
        {
            splits.push_back(s.substr(start_pos, end_pos - start_pos + 1));
            backtrack(ans, splits, s, end_pos + 1);
            splits.pop_back();
        }
    }
}

vector<vector<string>> solution_1(string s)
{
    vector<vector<string>> ans;
    vector<string> splits;
    backtrack(ans, splits, s, 0);
    return ans;
}

vector<vector<string>> Solution::partition(string s)
{
    return solution_1(s);
}