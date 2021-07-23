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

TreeNode *searchInBSTIteratively(TreeNode *root, int val)
{
    while (root != NULL)
    {
        if (root->val == val)
        {
            return root;
        }
        else if (val < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int findMinRecursively(TreeNode *root)
{
    if (root == NULL)
        return -1;
    if (root->left != NULL)
    {
        return findMinRecursively(root->left);
    }
    else
    {
        return root->val;
    }
}

int findMinItteratively(TreeNode *root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->val;
}

int main()
{
    return 0;
}