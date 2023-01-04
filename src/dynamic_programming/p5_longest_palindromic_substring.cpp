#include "dynamic_programming/dp.h"
#include <vector>
using namespace std;
using namespace dp;
// solution 1: dynamic programming
// time : O(n*n), space: O(n*n)
string solution_1(string s)
{
    string ans;
    int len = s.size();
    vector<vector<bool>> states(len, vector<bool>(len, false));
    for (auto i = len - 1; i >= 0; i--)
    {
        for (auto j = i; j < len; j++)
        {
            if (j - i >= 2)
            {
                states[i][j] = states[i + 1][j - 1] && (s[i] == s[j]);
            }
            else
            {
                states[i][j] = (s[i] == s[j]);
            }
            if (states[i][j] && j - i + 1 > ans.size())
            {
                ans = s.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}
// solution 2 two pointer
// time: O(n*n), space: O(n)
string solution_2(string s)
{
    string ans;
    int len = s.size();
    for (auto i = 0; i < len; i++)
    {
        int right = i;
        while (right < len && s[right] == s[i])
            right++;
        int left = i - 1;
        while (left >= 0 && right < len && s[left] == s[right])
        {
            left--;
            right++;
        }
        if (right - left - 1 > ans.size())
            ans = s.substr(left + 1, right - left - 1);
    }
    return ans;
}
string Solution::longestPalindrome(string s)
{
    return solution_2(s);
}