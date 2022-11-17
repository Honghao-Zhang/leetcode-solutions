#include "array/array.h"
#include <algorithm>
using namespace std;
// solution 1: insert the last k elements at front, then erase last k elements
void solution_1(vector<int> &nums, int k)
{
    k %= nums.size();
    nums.insert(nums.begin(), nums.end() - k, nums.end());
    nums.erase(nums.end() - k, nums.end());
}
// solution 2: use standard rotate
void solution_2(vector<int> &nums, int k)
{
    int n = nums.size();
    std::rotate(nums.begin(), nums.begin() + n - k % n, nums.end());
}
// solution 3: implement rotate manually
// this method is like two pointer in a linked list with cycle
void solution_3(vector<int> &nums, int k)
{
    int n = nums.size();
    auto center = nums.begin() + n - k % n;
    auto next = center;
    auto first = nums.begin();
    while (first != next)
    {
        swap(*first++, *next++);

        if (next == nums.end())
        {
            next = center;
        }
        else if (first == center)
        { // check first == center must behind checking next == nums.end()
          // otherwise algorithm will terminate by *next (*nums.end())
            center = next;
        }
    }
}

void my_array::rotate(vector<int> &nums, int k)
{
    solution_3(nums, k);
}