#include <iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

TreeNode *searchInBSTRecursively(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->val == val)
    {
        return root;
    }
    else if (val < root->val)
    {
        return searchInBSTRecursively(root->left, val);
    }
    else
    {
        return searchInBSTRecursively(root->right, val);
    }
}

int main()
{
    return 0;
}