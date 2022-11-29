#include "substring/substring.h"
#include <unordered_set>
#include <algorithm>
using namespace std;
using namespace substring;
// this solution won't work for test example (s = "aaaaaaa", wordDict =["aaaa", "aaa"])
bool solution_1_not_work(string s, vector<string> &wordDict)
{
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    int begin = 0, end = 0;
    while (end < s.size())
    {
        if (words.find(s.substr(begin, end - begin + 1)) != words.end())
        {
            begin = end + 1;
        }
        end++;
    }
    return (begin == s.size());
}
// solution 2: this solution won't work when s is long, wordDict is large
bool helper(const string &s, unordered_set<string> &words, int l, int r, int min_len, int max_len)
{
    //[l,r) defines current interval for searching
    if (r - l >= min_len && r - l <= max_len && words.find(s.substr(l, r - l)) != words.end())
        return true;
    for (int k = l; k < r - 1; k++)
    {
        if (helper(s, words, l, k + 1, min_len, max_len) && helper(s, words, k + 1, r, min_len, max_len))
            return true;
    }
    return false;
}

bool solution_2(string s, vector<string> &wordDict)
{
    // unordered_set<string> words(wordDict.begin(), wordDict.end());
    unordered_set<string> words;
    int min_len = s.size();
    int max_len = 0;
    for (auto str : wordDict)
    {
        min_len = min(min_len, static_cast<int>(str.size()));
        max_len = max(max_len, static_cast<int>(str.size()));
        words.insert(str);
    }
    return helper(s, words, 0, s.size(), min_len, max_len);
}

// solution 3
bool solution_3(string s, vector<string> &wordDict)
{
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    vector<bool> valid_sequence(s.size() + 1, false);
    valid_sequence[0] = true;
    for (auto i = 1; i <= s.size(); i++)
    {
        for (auto j = i - 1; j >= 0; j--)
        {
            if (valid_sequence[j])
            {
                string cur = s.substr(j, i - j);
                if (words.find(cur) != words.end())
                {
                    valid_sequence[i] = true;
                    break;
                }
            }
        }
    }
    return valid_sequence[s.size()];
}

bool solution_4(string s, vector<string> &wordDict)
{
    unordered_set<string> words;
    int min_len = s.size();
    int max_len = 0;
    for (auto str : wordDict)
    {
        min_len = min(min_len, static_cast<int>(str.size()));
        max_len = max(max_len, static_cast<int>(str.size()));
        words.insert(str);
    }
    vector<bool> valid_sequence(s.size() + 1, false);
    valid_sequence[0] = true;
    for (auto i = min_len; i <= s.size(); i++)
    {
        for (auto j = i - 1; j >= max(0, i - max_len); j--)
        {
            if (valid_sequence[j])
            {
                string cur = s.substr(j, i - j);
                if (words.find(cur) != words.end())
                {
                    valid_sequence[i] = true;
                    break;
                }
            }
        }
    }
    return valid_sequence[s.size()];
}

// solution 5
bool sameSequence(int idx, const string &s, const string &word)
{
    int k = 0;
    while (k < word.size())
    {
        if (s[idx] != word[k])
            return false;
        k++;
        idx++;
    }
    return true;
}

bool solution_5(string s, vector<string> &wordDict)
{
    vector<bool> valid(s.size() + 1, false);
    valid[0] = true;
    for (int i = 1; i <= s.size(); i++)
    {
        if (valid[i - 1])
        {
            int max_valid_len = s.size() - (i - 1);
            for (auto const &word : wordDict)
            {
                if (word.size() <= max_valid_len && sameSequence(i - 1, s, word))
                {
                    valid[i - 1 + word.size()] = true;
                }
            }
        }
    }
    return valid[s.size()];
}

bool Solution::wordBreak(string s, vector<string> &wordDict)
{
    return solution_5(s, wordDict);
}