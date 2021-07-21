#include "1_BinaryTree.cpp"

pair<int, int> heightDiameter(BTNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int leftHeight = leftAns.first;
    int leftDiameter = leftAns.second;

    int rightHeight = rightAns.first;
    int rightDiameter = rightAns.second;

    int height = 1 + max(leftHeight, rightHeight);
    int diameter = max(rightHeight + leftHeight, max(leftDiameter, rightDiameter));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int diameterOfBinaryTree(BTNode<int> *root)
{
    pair<int, int> p = heightDiameter(root);
    return p.second;
}
int main()
{
    BTNode<int> *root = takeInputLevelWise();
    cout << diameterOfBinaryTree(root);
    return 0;
}