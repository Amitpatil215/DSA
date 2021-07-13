#include "1_BinaryTree.cpp"

bool helper(BTNode<int> *left, BTNode<int> *right)
{
    if (left == NULL && right != NULL)
        return false;
    if (left != NULL && right == NULL)
        return false;
    if (left == NULL && right == NULL)
        return true;
    if (left->data != right->data)
        return false;

    return helper(left->left, right->right) && helper(left->right, right->left);
}

bool isSymmentric(BTNode<int> *root)
{
    if (root == NULL)
        return true;
    return helper(root->left, root->right);
}

int main()
{
    BTNode<int> *root = takeInputLevelWise(); // 1 2 2 3 4 4 3 -1 -1 -1 -1 -1 -1 -1 -1
    cout << isSymmentric(root);
    return 0;
}