#include "breadth_first_search/bfs.h"
#include <gtest/gtest.h>
using namespace std;
using namespace bfs;

TEST(WordSearch, example_1)
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    string word{"ABCCED"};
    Solution obj;
    EXPECT_TRUE(obj.exist(board, word));
}

TEST(WordSearch, example_2)
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'E', 'S'},
                               {'A', 'D', 'E', 'E'}};
    string word{"ABCESEEEFS"};
    Solution obj;
    EXPECT_TRUE(obj.exist(board, word));
}

TEST(WordSearch, example_3)
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'}};
    string word{"ABCB"};
    Solution obj;
    EXPECT_FALSE(obj.exist(board, word));
}