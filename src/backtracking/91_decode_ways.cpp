#include "backtracking/backtracking.h"
#include <vector>
using namespace std;
using namespace backtracking;

int solution_1(string s)
{
    if (s.empty())
        return 0;
    if (s[0] == '0')
        return 0;
    int len = s.size();
    if (len >= 2)
    {
        int ans = 0;
        if ((s[0] == '1') || (s[0] == '2' && s[1] - '0' >= 0 && s[1] - '6' <= 0))
        {
            if (len == 2)
                ans += 1;
            else
                ans += solution_1(s.substr(2, len - 2));
        }
        ans += solution_1(s.substr(1, len - 1));
        return ans;
    }
    if (len == 1)
        return 1;

    return 0;
}

int solution_2(string s)
{
    if (s.empty())
        return 0;
    int len = s.size();
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    for (auto i = 1; i <= len; i++)
    {
        if (s[i - 1] == '0' && (s[i - 2] - '0') * 10 > 26)
            return 0;
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (i >= 2 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[len];
}

int Solution::numDecodings(string s)
{
    return solution_2(s);
}