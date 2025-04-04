#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
// (i.e., from left to right, then right to left for the next level and alternate between).
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int levelSize = q.size();
        std::vector<int> currentLevel(levelSize);

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *node = q.front();
            q.pop();

            int index = leftToRight ? i : (levelSize - 1 - i);
            currentLevel[index] = node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        result.push_back(currentLevel);
        leftToRight = !leftToRight;
    }

    return result;
}