#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();

    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    // Step 1: Use temporary states to mark transitions
    // 0 : dead -> dead
    // 1 : live -> live
    // 2 : live -> dead
    // 3 : dead -> live

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int liveNeighbors = 0;

            for (auto [dx, dy] : directions)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    if (board[x][y] == 1 || board[x][y] == 2)
                    {
                        ++liveNeighbors;
                    }
                }
            }

            if (board[i][j] == 1)
            {
                // Rule 1 or Rule 3
                if (liveNeighbors < 2 || liveNeighbors > 3)
                {
                    board[i][j] = 2; // live -> dead
                }
            }
            else
            {
                // Rule 4
                if (liveNeighbors == 3)
                {
                    board[i][j] = 3; // dead -> live
                }
            }
        }
    }

    // Step 2: Finalize the board state
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 2)
            {
                board[i][j] = 0;
            }
            else if (board[i][j] == 3)
            {
                board[i][j] = 1;
            }
        }
    }
}

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}