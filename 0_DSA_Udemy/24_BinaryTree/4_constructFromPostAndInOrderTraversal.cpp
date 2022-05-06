#include "1_BinaryTree.cpp"
BTNode<int> *buildTreeHelper(vector<int> inorder, vector<int> postOrder, int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd)
{
    //base case
    if (inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    int rootData = postOrder[postOrderEnd];

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
    int leftpostOrderStart = postOrderStart;
    int leftpostOrderEnd = leftpostOrderStart + leftInOrderEnd - leftInOrderStart;

    int rightInOrderStart = rootIndex + 1;
    int rightInOrderEnd = inOrderEnd;
    int rightpostOrderStart = leftpostOrderEnd + 1;
    int rightpostOrderEnd = postOrderEnd - 1;

    BTNode<int> *root = new BTNode<int>(rootData);
    // build left sub tree
    root->left = buildTreeHelper(inorder, postOrder, leftInOrderStart, leftInOrderEnd, leftpostOrderStart, leftpostOrderEnd);
    // build right sub tree
    root->right = buildTreeHelper(inorder, postOrder, rightInOrderStart, rightInOrderEnd, rightpostOrderStart, rightpostOrderEnd);

    return root;
}

BTNode<int> *buildTree(vector<int> &postOrder, vector<int> &inorder)
{
    int size = inorder.size();
    return buildTreeHelper(inorder, postOrder, 0, size - 1, 0, size - 1);
}
int main()
{
    vector<int> postOrder = {9,15,7,20,3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    BTNode<int> *root = buildTree(postOrder, inorder);
    InOrderTrraversal(root);
}