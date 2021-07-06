#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
};

void printTree(TreeNode<int> *root)
{
    //edge case not a base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " , ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode<int> *takeInputUsingRecursion()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);
    int childrenSize;
    cout << "Enter the no of children of " << rootData << endl;
    cin >> childrenSize;
    for (int i = 0; i < childrenSize; i++)
    {
        TreeNode<int> *child = takeInputUsingRecursion();
        root->children.push_back(child);
    }
    return root;
}

int main()
{
    TreeNode<int> *root = takeInputUsingRecursion();
    printTree(root);
    return 0;
}