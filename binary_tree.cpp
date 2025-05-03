#include <iostream>
#include <climits>
#include <unordered_map>
#include <vector>

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

constexpr auto MAX_ABSOLUTE_VAL = 3000;
array<int, 2 * MAX_ABSOLUTE_VAL + 1> inorderValToIdx;

class BtFromPreorderAndInorder
{
    static TreeNode *buildtree(
        const vector<int> &preorder,
        int preOrderStartIdx,
        int preOrderLastIdx,
        const vector<int> &inorder,
        int inOrderStartIdx,
        int inOrderLastIdx)
    {
        const auto val = preorder[preOrderStartIdx];
        const auto root = new TreeNode(val);

        const int inOrderValIdx = inorderValToIdx[MAX_ABSOLUTE_VAL + val];
        const int countOfNodesOnLeft = inOrderValIdx - inOrderStartIdx;
        if (countOfNodesOnLeft > 0)
        {
            root->left = buildtree(
                preorder,
                preOrderStartIdx + 1,
                preOrderStartIdx + countOfNodesOnLeft,
                inorder,
                inOrderStartIdx,
                inOrderValIdx - 1);
        }

        if (preOrderLastIdx - preOrderStartIdx > countOfNodesOnLeft)
        {
            root->right = buildtree(
                preorder,
                preOrderStartIdx + countOfNodesOnLeft + 1,
                preOrderLastIdx,
                inorder,
                inOrderValIdx + 1,
                inOrderLastIdx);
        }

        return root;
    }

public:
    static TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); ++i)
            inorderValToIdx[MAX_ABSOLUTE_VAL + inorder[i]] = i;

        return buildtree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr || root == p || root == q)
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != nullptr && right != nullptr)
        return root;

    return left != nullptr ? left : right;
}

class BSTIterator
{
public:
    TreeNode *head, *cur;

    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        dfs(root->left);

        TreeNode *right = root->right;

        cur->right = root;
        cur = cur->right;
        cur->left = cur->right = NULL;

        dfs(right);
    }
    BSTIterator(TreeNode *root)
    {
        head = new TreeNode();
        cur = head;
        dfs(root);
        cur = head;
    }

    int next()
    {
        cur = cur->right;
        return cur->val;
    }
    
    bool hasNext()
    {
        return cur->right != NULL;
    }
};