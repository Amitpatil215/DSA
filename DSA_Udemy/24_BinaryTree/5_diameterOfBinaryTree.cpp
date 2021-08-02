#include "1_BinaryTree.cpp"

// Complexity
// T=O(n)
int height(BTNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(BTNode<int> *root)
{
    //base case
    if (root == NULL)
    {
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);
    return max(option1, max(option2, option3));
}
int main()
{
    BTNode<int> *root = takeInputLevelWise();
    cout << diameterOfBinaryTree(root);
    return 0;
}