#ifndef MY_SOLUTIONS_BFS_H
#define MY_SOLUTIONS_BFS_H

#include <vector>
#include <string>

namespace bfs
{
    class Solution
    {
    public:
        // 994 rotting oranges
        int orangesRotting(std::vector<std::vector<int>> &grid);
        // 79 word search
        bool exist(std::vector<std::vector<char>> &board, std::string word);
    };
};

#endif