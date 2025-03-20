#include <iostream>
#include <climits>

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

class BinaryTreeMaximumPathSum
{
public:
    int maxSum;

    int findMaxPath(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = max(0, findMaxPath(root->left));
        int right = max(0, findMaxPath(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode *root)
    {
        maxSum = INT_MIN;
        findMaxPath(root);
        return maxSum;
    }
};