#include "string/string.h"
#include <stack>
#include <cctype>
#include <regex>
#include <iostream>
using namespace std;
using namespace my_string;

int digit(char c)
{
    if (c - '0' >= 0 && c - '9' <= 0)
        return (c - '0');
    else
        return -1;
}

int number(const string &s, int &idx)
{
    int ans = 0;
    while (idx < s.size())
    {
        if (-1 != digit(s[idx]))
        {
            ans = 10 * ans + digit(s[idx]);
            idx++;
        }
        else
        {
            break;
        }
    }
    return ans;
}

string content(const string &s, int &idx, int repeats)
{
    string ans;
    int num = 1;
    string tmp;
    while (idx < s.size())
    {
        if (s[idx] == '[')
        {
            ++idx;
            tmp += content(s, idx, num);
        }
        else if (-1 != digit(s[idx]))
        {
            num = number(s, idx);
        }
        else if (s[idx] == ']')
        {
            ++idx;
            break;
        }
        else
        {
            tmp += s[idx];
            ++idx;
        }
    }
    for (auto i = 0; i < repeats; i++)
        ans += tmp;
    return ans;
}

string solution_1(string s)
{
    int idx = 0;
    return content(s, idx, 1);
}

// solution 2: using stack and vector<pair<int, string>>
string decode(const string &str, int &idx)
{
    string ans;
    int repeat = 1;
    int number = 0;
    while (idx < str.size())
    {
        if (isdigit(str[idx]))
        {
            number = number * 10 + (str[idx] - '0');
            repeat = number;
            idx++;
        }
        else if (str[idx] == '[')
        {
            string str_in_bracket = decode(str, ++idx);
            while (repeat-- > 0)
            {
                ans += str_in_bracket;
            }
            number = 0;
            repeat = 1;
        }
        else if (str[idx] == ']')
        {
            idx++;
            return ans;
        }
        else
        {
            ans += str[idx];
            idx++;
        }
    }
    return ans;
}

string solution_2(string s)
{
    int idx = 0;
    return decode(s, idx);
}
// solution 3: using regular expression
string solution_3(string s)
{
    regex r1(R"(([a-f]*)(\d*)\[)");
    smatch sm;
    while (regex_search(s, sm, r1))
    {
        std::cout << "Prefix: '" << sm.prefix() << "'\n";
        for (size_t i = 0; i < sm.size(); ++i)
            std::cout << i << ": " << sm[i] << '\n';
        std::cout << "Suffix: '" << sm.suffix() << "\'\n\n";
    }
    return string("abc");
}
string Solution::decodeString(string s)
{
    return solution_3(s);
}