#include <iostream>
#include <limits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode *root, long minVal, long maxVal)
{
    if (!root)
        return true;

    if (root->val <= minVal || root->val >= maxVal)
        return false;

    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
}

TreeNode *createTestTree()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

int main()
{
    TreeNode *root = createTestTree();
    if (isValidBST(root))
    {
        std::cout << "valid BST.\n";
    }
    else
    {
        std::cout << "invalid BST.\n";
    }
    return 0;
}