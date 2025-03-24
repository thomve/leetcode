#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class ConstructQuadTree
{
public:
    Node *solve(vector<vector<int>> &grid, int x, int y, int length)
    {
        if (length == 1)
        {
            return new Node(grid[x][y], true);
        }

        Node *topLeft = solve(grid, x, y, length / 2);
        Node *topRight = solve(grid, x, y + length / 2, length / 2);
        Node *bottomLeft = solve(grid, x + length / 2, y, length / 2);
        Node *bottomRight = solve(grid, x + length / 2, y + length / 2, length / 2);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            return new Node(topLeft->val, true);
        }

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node *construct(vector<vector<int>> &grid)
    {
        return solve(grid, 0, 0, grid.size());
    }
};