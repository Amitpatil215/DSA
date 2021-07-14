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

BTNode<int> *takeInputLevelWise()
{
    // For first root Node
    int rootData;
    cout << "enter root data" << endl;
    cin >> rootData;
    BTNode<int> *root = new BTNode<int>(rootData);
    queue<BTNode<int> *> q;
    q.push(root);

    // for remaining tree
    while (!q.empty())
    {
        BTNode<int> *front = q.front();
        q.pop();
        // take input for left child
        cout << "Enter left child of " << front->data << endl;

        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BTNode<int> *leftChild = new BTNode<int>(leftChildData);
            q.push(leftChild);
            front->left = leftChild;
        }

        // take input for right child
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BTNode<int> *rightChild = new BTNode<int>(rightChildData);
            q.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

void printTreeLevelWise(BTNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BTNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BTNode<int> *front = q.front();

        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int countNode(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}
void InOrderTrraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    InOrderTrraversal(root->left);  // left
    cout << root->data;             // data
    InOrderTrraversal(root->right); // right
}
void PreOrderTrraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data;              // data
    PreOrderTrraversal(root->left);  // left
    PreOrderTrraversal(root->right); // right
}
void PostOrderTrraversal(BTNode<int> *root)
{
    if (root == NULL)
        return;
    PostOrderTrraversal(root->left);  // left
    PostOrderTrraversal(root->right); // right
    cout << root->data;               // data
}

int maxDepth(BTNode<int> *root)
{

    if (root == NULL)
        return 0;

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isNodePresent(BTNode<int> *root, int data)
{
    if (root == NULL)
        return false;
    if (root->data == data)
    {
        return true;
    }
    return isNodePresent(root->left, data) || isNodePresent(root->right, data);
}
int findMinValue(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    int rootData = root->data;
    int leftMin = findMinValue(root->left);
    int rightMin = findMinValue(root->right);
    return min(rootData, min(leftMin, rightMin));
}
int findMaxValue(BTNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    int rootData = root->data;
    int leftMin = findMinValue(root->left);
    int rightMin = findMinValue(root->right);
    return max(rootData, max(leftMin, rightMin));
}

int countLeafNode(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right==NULL)
    {
        return 1;
    }
    return countLeafNode(root->left) + countLeafNode(root->right);
}

/* int main()
{
    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);

    // root->left = n1;
    // root->right = n2;

    // BTNode<int> *root = takeInputRecursive(); // 1 2 -1 -1 3 -1 -1
    BTNode<int> *root = takeInputLevelWise(); // 1 2 3 -1 -1 -1 -1

    // printTreeRecursive(root);
    //printTreeLevelWise(root);
    // InOrderTrraversal(root);
    // PreOrderTrraversal(root);
    // PostOrderTrraversal(root);
    // cout << isNodePresent(root, 3);
    // cout << findMinValue(root);
    // cout << findMaxValue(root);
    cout << countLeafNode(root);
    // cout << "Max height " << maxDepth(root) << endl;
    // cout
    //     << "Nodes Count " << countNode(root) << endl;
    delete root;
    return 0;
}
 */