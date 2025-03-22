#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    NumberOfIslands noi;
    cout << "Number of islands: " << noi.numIslands(grid) << endl;
    return 0;
}
