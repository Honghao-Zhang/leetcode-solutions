#include "dynamic_programming/dp.h"
#include <unordered_map>
using namespace std;
using namespace dp;

vector<int> solution_1(string s, string p)
{
    unordered_map<char, int> dict;
    int len = p.size();
    for (auto c : p)
        dict[c]++;
    vector<int> ans;
    int start = 0, end = 0;
    while (end < s.size())
    {
        if (dict.find(s[end]) != dict.end())
        {
            if (dict[s[end]] > 0)
            {
                dict[s[end]]--;
                len--;
                if (len == 0)
                {
                    ans.push_back(start);
                    dict[s[start]]++;
                    len++;
                    start++;
                }
            }
            else
            {
                while (start < end && s[start] != s[end])
                {
                    dict[s[start]]++;
                    len++;
                    start++;
                }
                start++;
            }
        }
        else
        {
            while (start < end)
            {
                dict[s[start]]++;
                len++;
                start++;
            }
            start = end + 1;
        }
        end++;
    }
    return ans;
}

// solution 2
vector<int> solution_2(string s, string p)
{
    vector<int> chars(26, 0);
    int32_t len = p.size(), char_num = p.size();
    for (auto c : p)
        chars[c - 'a']++;
    vector<int> ans;
    int32_t start = 0, end = 0;
    while (end < s.size())
    {
        if (--chars[s[end] - 'a'] >= 0)
        {
            char_num--;
        }
        end++;
        if (char_num == 0)
        {
            ans.push_back(start);
        }
        while (start <= end - len)
        {
            if (++chars[s[start] - 'a'] > 0)
            {
                char_num++;
            }
            start++;
        }
    }
    return ans;
}

vector<int> Solution::findAnagrams(string s, string p)
{
    return solution_2(s, p);
}