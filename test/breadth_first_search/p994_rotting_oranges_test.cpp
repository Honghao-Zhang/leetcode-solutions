#include "bfs.h"
#include <gtest/gtest.h>

TEST(RottingOranges, example_1)
{
    std::vector<std::vector<int>> grids{{2, 1, 1},
                                        {1, 1, 0},
                                        {0, 1, 1}};
    bfs::Solution obj;
    EXPECT_EQ(4, obj.orangesRotting(grids));
}

TEST(RottingOranges, example_2)
{
    std::vector<std::vector<int>> grids{{2, 1, 1},
                                        {0, 1, 1},
                                        {1, 0, 1}};
    bfs::Solution obj;
    EXPECT_EQ(-1, obj.orangesRotting(grids));
}

TEST(RottingOranges, example_3)
{
    std::vector<std::vector<int>> grids{{0, 2}};
    bfs::Solution obj;
    EXPECT_EQ(0, obj.orangesRotting(grids));
}

TEST(RottingOranges, no_rotten)
{
    std::vector<std::vector<int>> grids{{1, 1, 1},
                                        {0, 1, 1},
                                        {1, 0, 1}};
    bfs::Solution obj;
    EXPECT_EQ(-1, obj.orangesRotting(grids));
}