#include <bits/stdc++.h>
using namespace std;

// Binary Tree Class Implementaion
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
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
    BTNode<int> *root;

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

    bool _hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
            return NULL;

        if (node->data == data)
            return true;

        if (data < node->data)
            return _hasData(node->left, data);
        else
            return _hasData(node->right, data);
    }

    BTNode<int> *_insert(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BTNode<int> *root = new BTNode<int>(data);
            return root;
        }

        if (data < node->data)
        {
            node->left = _insert(node->left, data);
        }
        else
        {
            node->right = _insert(node->right, data);
        }

        return node;
    }

public:
    BST()
    {
        root = NULL;
    };

    ~BST()
    {
        delete root;
    };

    void deleteData(int data){};
    void insert(int data)
    {
        root = _insert(root, data);
    };
    bool hasData(int data)
    {
        return _hasData(root, data);
    };
    void print()
    {
        printTreeRecursive(root);
    };
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    b.print();
    /* 10 : L-5 R-20
       5 : L-3 R-73 :
       7 :
       20 : L-15
       15 :
    */

    cout << b.hasData(3) << endl;  //1
    cout << b.hasData(12) << endl; //0
    return 0;
}