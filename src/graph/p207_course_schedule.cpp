#include "graph/graph.h"
#include <queue>
using namespace std;
using namespace graph;

using MyGraph = vector<vector<int>>;

// solution 1: torpological sort / breadth first search
bool solution_1(int numCourses, vector<vector<int>> &prerequisites)
{
    MyGraph g(numCourses);
    vector<int> degree(numCourses, 0);
    for (auto requisite : prerequisites)
    {
        g[requisite.at(1)].push_back(requisite.at(0));
        degree[requisite.at(0)]++;
    }
    queue<int> start_courses;
    for (auto idx = 0; idx < numCourses; idx++)
    {
        if (!degree[idx])
            start_courses.push(idx);
    }
    while (!start_courses.empty())
    {
        int course = start_courses.back();
        start_courses.pop();
        numCourses--;
        for (auto c : g[course])
        {
            degree[c]--;
            if (degree[c] == 0)
                start_courses.push(c);
        }
    }
    return numCourses == 0;
}

MyGraph constructGraph(vector<vector<int>> &prerequisites, int n)
{
    MyGraph g(n);
    for (auto requisites : prerequisites)
    {
        g[requisites.at(1)].push_back(requisites.at(0));
    }
    return g;
}

bool dfsVisit(const MyGraph &g, int vertex, vector<bool> &visiting, vector<bool> &visited)
{
    if (visiting[vertex])
        return false; // there must be a cycle in current tree path, 1->2->3->4->1
    if (visited[vertex])
        return true; // meet a visited vertex, recursion ends here, graph has edges like: 1->2->3, 4->2->3

    visiting[vertex] = true;
    visited[vertex] = true;
    for (auto v : g[vertex])
    {
        if (!dfsVisit(g, v, visiting, visited))
            return false;
    }
    visiting[vertex] = false;
    return true;
}

// solution 2 : depth first search
bool solution_2(int numCourses, vector<vector<int>> &prerequisites)
{
    MyGraph g = constructGraph(prerequisites, numCourses);
    vector<bool> visiting(numCourses), visited(numCourses);
    for (auto idx = 0; idx < numCourses; ++idx)
    {
        if (visited[idx])
            continue;
        if (!dfsVisit(g, idx, visiting, visited))
            return false;
    }
    return true;
}
bool Solution::canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    return solution_2(numCourses, prerequisites);
}
