#include "dynamic_programming/dp.h"
#include <iostream>
using namespace std;
using namespace dp;

int solution_1(std::string text1, std::string text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> matches(m + 1, vector<int>(n + 1, 0));
    std::cout << "  | ";
    for (auto t : text2)
        std::cout << t << " ";
    std::cout << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    for (auto i = 1; i <= m; i++)
    {
        std::cout << text1[i - 1] << " | ";
        for (auto j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                matches[i][j] = matches[i - 1][j - 1] + 1;
            }
            else
            {
                matches[i][j] = max(matches[i][j - 1], max(matches[i - 1][j], matches[i - 1][j - 1]));
            }
            std::cout << matches[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return matches[m][n];
}
// solution 2: with space optimization
int solution_2(string txt1, string txt2)
{
    string *long_str = &txt1, *short_str = &txt2;
    if (txt1.size() < txt2.size())
    {
        long_str = &txt2;
        short_str = &txt1;
    }
    int l = long_str->size(), s = short_str->size();
    vector<int> matches(s + 1, 0);
    int diagonal = 0;
    int min_match = 0;
    for (auto i = 0; i < l; i++)
    {
        diagonal = matches[0];
        for (auto j = 1; j <= s; ++j)
        {
            int tmp = matches[j];
            if (long_str->at(i) == short_str->at(j - 1))
            {
                matches[j] = diagonal + 1;
                if (matches[j] > min_match)
                {
                    min_match = matches[j];
                    std::cout << long_str->at(i) << std::endl;
                }
            }
            else
            {
                // matches[j] = max(matches[j], max(matches[j - 1], diagonal));
                matches[j] = max(matches[j], matches[j - 1]);
            }
            diagonal = tmp;
        }
    }
    return matches[s];
}

// solution 3: recursive
int helper(const string &txt1, int i, const string &txt2, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (txt1[i] == txt2[j])
        return 1 + helper(txt1, i - 1, txt2, j - 1);
    else
        return max(helper(txt1, i - 1, txt2, j), helper(txt1, i, txt2, j - 1));
}

int solution_3(string text1, string text2)
{
    return helper(text1, text1.size() - 1, text2, text2.size() - 1);
}

int Solution::longestCommonSubsequence(std::string text1, std::string text2)
{
    return solution_1(text1, text2);
}