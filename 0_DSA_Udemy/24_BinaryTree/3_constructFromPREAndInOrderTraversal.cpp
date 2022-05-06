#include "1_BinaryTree.cpp"
BTNode<int> *buildTreeHelper(vector<int> inorder, vector<int> preorder, int inOrderStart, int inOrderEnd, int preOrderStart, int preOrderEnd)
{
    // base case
    if (inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int rootData = preorder[preOrderStart];

    int rootIndex = -1;

    for (int i = inOrderStart; i <= inOrderEnd; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInOrderStart = inOrderStart;
    int leftInOrderEnd = rootIndex - 1;
    int leftPreOrderStart = preOrderStart + 1;
    int leftPreOrderEnd = leftPreOrderStart + leftInOrderEnd - leftInOrderStart;

    int rightInOrderStart = rootIndex + 1;
    int rightInOrderEnd = inOrderEnd;
    int rightPreOrderStart = leftPreOrderEnd + 1;
    int rightPreOrderEnd = preOrderEnd;

    BTNode<int> *root = new BTNode<int>(rootData);
    // build left sub tree
    root->left = buildTreeHelper(inorder, preorder, leftInOrderStart, leftInOrderEnd, leftPreOrderStart, leftPreOrderEnd);
    // build right sub tree
    root->right = buildTreeHelper(inorder, preorder, rightInOrderStart, rightInOrderEnd, rightPreOrderStart, rightPreOrderEnd);

    return root;
}

BTNode<int> *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();
    return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
}
int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    BTNode<int> *root = buildTree(preorder, inorder);
    InOrderTrraversal(root);
}