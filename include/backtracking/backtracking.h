#ifndef MY_SOLUTIONS_BACKTRACKING_H
#define MY_SOLUTIONS_BACKTRACKING_H
#include <vector>
#include <string>
namespace backtracking
{
	class Solution
	{
	public:
		// 51 N Queens
		std::vector<std::vector<std::string>> solveNQueens(int n);
		// 52 N Queens II
		int totalNQueens(int n);
		// 131 palindome partioning
		std::vector<std::vector<std::string>> partition(std::string s);
		// 91 decode ways
		int numDecodings(std::string s);
		// 22 generate parentheses
		std::vector<std::string> generateParenthesis(int n);
	};
};
#endif
