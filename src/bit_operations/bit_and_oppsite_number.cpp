#include "bit_operations/bit_operations.h"

using namespace std;
using namespace bit_operations;

vector<int> Solution::powerTwoSum(int n)
{
    vector<int> ans;
    int m = n;
    while (m != 0)
    {
        // m & (-m) It's an old trick that gives a number with a single bit in it, the bottom bit that was set in n.
        // same as n & (~n + 1), equivalent to bitset<N> m(n); m[m.size()-1];
        int res = m & (-m);
        ans.push_back(res);
        m -= res;
    }
    return ans;
}
