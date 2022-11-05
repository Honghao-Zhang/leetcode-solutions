#include "dynamic_programming/dp.h"
#include <gtest/gtest.h>

TEST(RottingOranges, no_rotting)
{
    std::vector<std::vector<int>> grids{{1, 1, 1},
                                        {1, 1, 1},
                                        {1, 1, 1}};
    dp::Solution obj;
    EXPECT_EQ(0, obj.orangesRotting(grids));
}
