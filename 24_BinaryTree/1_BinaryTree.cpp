#include <bits/stdc++.h>
using namespace std;

template <typename T>

class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // destructor will delete sub tree recursively
    ~BTNode()
    {
        delete this->left;
        delete this->right;
    }
};

void printTreeRecursive(BTNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " : ";
    if (root->left != NULL)
        cout << "L-" << root->left->data << " ";
    if (root->right != NULL)
        cout << "R-" << root->right->data;
    cout << endl;
    printTreeRecursive(root->left);
    printTreeRecursive(root->right);
}

BTNode<int> *takeInputRecursive()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    // create root Node
    BTNode<int> *root = new BTNode<int>(rootData);

    // take input for left node
    BTNode<int> *leftChild = takeInputRecursive();
    // take input for right node
    BTNode<int> *rightChild = takeInputRecursive();

    // connect
    root->left = leftChild;
    root->right = rightChild;
}

int main()
{
    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);

    // root->left = n1;
    // root->right = n2;

    BTNode<int> *root = takeInputRecursive(); // 1 2 -1 -1 3 -1 -1
    printTreeRecursive(root);
    delete root;
    return 0;
}