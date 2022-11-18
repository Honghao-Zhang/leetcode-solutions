#include "hash/hash.h"
#include <unordered_map>
using namespace std;

vector<int> my_hash::partitionLabels(string s)
{
    unordered_map<char, pair<int, int>> chars;
    for (auto idx = 0; idx < s.size(); ++idx)
    {
        if (chars.find(s[idx]) == chars.end())
            chars[s[idx]] = {idx, idx};
        else
            chars[s[idx]].second = idx;
    }
    vector<int> ans;
    int start = 0, end = 0;
    for (int i = 0; i < s.size();)
    {
        start = min(start, chars[s[i]].first);
        end = max(end, chars[s[i]].second);
        i++;
        if (i > end)
        {
            ans.push_back(i - start);
            start = i;
        }
    }
    return ans;
}