#ifndef MY_SOLUTIONS_SUBSTRING_H
#define MY_SOLUTIONS_SUBSTRING_H
#include <string>
#include <vector>
namespace substring
{
	class Solution
	{
	public:
		// 76 minimum window substring
		std::string minWindow(std::string s, std::string t);
		// 139 word break
		bool wordBreak(std::string s, std::vector<std::string> &wordDict);
	};
};
#endif
