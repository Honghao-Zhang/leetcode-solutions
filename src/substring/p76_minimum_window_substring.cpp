#include "substring/substring.h"
#include <unordered_map>
#include <vector>
using namespace std;
using namespace substring;

string solution_1(string s, string t)
{
    unordered_map<char, int> chars;
    for (auto c : t)
        chars[c]++;
    int start = 0, end = 0;
    int char_num = t.size();
    int min_len = s.size() + 1;
    int min_start = 0;
    while (end < s.size())
    {
        if (chars.find(s[end]) != chars.end())
        {
            chars[s[end]]--;
            if (chars[s[end]] >= 0)
                char_num--;
        }
        while (char_num == 0)
        {
            if (end - start + 1 < min_len)
            {
                min_len = end - start + 1;
                min_start = start;
            }
            if (chars.find(s[start]) != chars.end())
            {
                chars[s[start]]++;
                if (chars[s[start]] > 0)
                    char_num++;
            }
            start++;
        }
        end++;
    }
    if (min_len == s.size() + 1)
        return "";
    else
        return s.substr(min_start, min_len);
}

string solution_2(string s, string t)
{
    vector<int> chars(128, 0);
    for (auto c : t)
        chars[c]++;
    int start = 0, end = 0;
    int char_num = t.size();
    int min_len = s.size() + 1;
    int min_start = 0;
    while (end < s.size())
    {
        if (chars[s[end]] > 0)
            char_num--;
        chars[s[end]]--;
        end++;
        while (char_num == 0)
        {
            if (end - start < min_len)
            {
                min_len = end - start;
                min_start = start;
            }
            chars[s[start]]++;
            if (chars[s[start]] > 0)
                char_num++;
            start++;
        }
    }
    if (min_len == s.size() + 1)
        return "";
    else
        return s.substr(min_start, min_len);
}

string Solution::minWindow(string s, string t)
{
    return solution_2(s, t);
}