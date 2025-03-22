#include <iostream>
#include <vector>
#include <queue>


using namespace std;

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are all surrounded by water.
class NumberOfIslands
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Check if we are out of bounds or at a water cell
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        {
            return;
        }

        // cell as visited by setting it to '0'
        grid[i][j] = '0';

        // Explore all four directions (up, down, left, right)
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int num_islands = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    num_islands++;
                    dfs(grid, i, j);
                }
            }
        }

        return num_islands;
    }
};

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.
class CourseSchedule
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        // Build adjacency list and in-degree array
        for (auto &pre : prerequisites)
        {
            int course = pre[0], prereq = pre[1];
            adjList[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;

        // Push all courses with 0 in-degree (no prerequisites) into the queue
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int course = q.front();
            q.pop();
            count++;

            for (int neighbor : adjList[course])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        return count == numCourses;
    }
};

int main()
{
    // Number of Islands
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    NumberOfIslands noi;
    cout << "Number of islands: " << noi.numIslands(grid) << endl;

    // Course Schedule
    CourseSchedule cs;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}};
    int numCourses = 4;
    
    cout << (cs.canFinish(numCourses, prerequisites) ? "True" : "False") << endl;
    
    return 0;
}
