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

int main()
{
    BTNode<int> *root = new BTNode<int>(1);
    BTNode<int> *n1 = new BTNode<int>(2);
    BTNode<int> *n2 = new BTNode<int>(3);

    root->left = n1;
    root->right = n2;
    printTreeRecursive(root);
    delete root;
    return 0;
}