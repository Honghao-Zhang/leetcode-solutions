#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>
using namespace std;
using namespace dp;
TEST(LISExtension, example)
{
    vector<int> nums{2, 6, 8, 3, 4, 5, 1};
    Solution obj;
    auto res = obj.pathOfLIS(nums);
}