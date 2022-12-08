#include "dynamic_programming/dp.h"
#include <vector>
using namespace std;
using namespace dp;
// solution 1: dynamic programming
void solve(int i, vector<int> &nums)
{
    for (int j = 1; j * j <= i; j++)
    {
        nums[i] = min(nums[i], nums[i - j * j] + 1);
    }
}

int solution_1(int n)
{
    vector<int> numbers(n + 1, n + 1);
    numbers[0] = 0;
    for (auto i = 1; i <= n; i++)
    {
        solve(i, numbers);
    }
    return numbers[n];
}

int solution_1_1(int n)
{
    vector<int> numbers(n + 1, n + 1);
    numbers[0] = 0;
    for (auto i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            numbers[i] = min(numbers[i], numbers[i - j * j] + 1);
        }
    }
    return numbers[n];
}

int Solution::numSquares(int n)
{
    return solution_1_1(n);
}