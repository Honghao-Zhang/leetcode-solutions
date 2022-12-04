#include "graph/graph.h"
#include <gtest/gtest.h>
using namespace std;
using namespace graph;

TEST(CourseSchedule, example_1)
{
    int numCourses = 2;
    vector<vector<int>> prerequisites{{1, 0}, {0, 1}};
    Solution obj;
    EXPECT_FALSE(obj.canFinish(numCourses, prerequisites));
}