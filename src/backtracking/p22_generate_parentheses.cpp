#include "backtracking/backtracking.h"

using namespace std;
using namespace backtracking;

void addParenthesis_1(vector<string> &ans, string cur, int n, int m)
{
    if (n == 0 && m == 0)
    {
        ans.push_back(cur);
        return;
    }
    // this statement can be removed behind next statement
    // only the order of strings in ans will be changed.
    // if (m > 0)
    // {
    //     addParenthesis_1(ans, cur + ")", n, m - 1);
    // }
    if (n > 0)
    {
        addParenthesis_1(ans, cur + "(", n - 1, m + 1);
    }
    if (m > 0)
    {
        addParenthesis_1(ans, cur + ")", n, m - 1);
    }
}

vector<string> solution_1(int n)
{
    vector<string> ans;
    addParenthesis_1(ans, "", n, 0);
    return ans;
}

void addParenthesis_2(vector<string> &ans, string cur, int n, int m)
{
    if (n == 0 && m == 0)
    {
        ans.push_back(cur);
        return;
    }
    if (m > n)
    {
        addParenthesis_2(ans, cur + ")", n, m - 1);
    }
    if (n > 0)
    {
        addParenthesis_2(ans, cur + "(", n - 1, m);
    }
    // this statement can be removed before previous statement
    // only the order of strings in ans will be changed.
    // if (m > n)
    // {
    //     addParenthesis_2(ans, cur + ")", n, m - 1);
    // }
}

vector<string> solution_2(int n)
{
    vector<string> ans;
    addParenthesis_2(ans, "", n, n);
    return ans;
}

vector<string> Solution::generateParenthesis(int n)
{
    return solution_2(n);
}
