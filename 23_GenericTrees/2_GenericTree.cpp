#include <iostream>
#include <vector>
#include <queue>
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

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    //create node
    TreeNode<int> *root = new TreeNode<int>(rootData);
    //Push
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int n;
        cout << "Enter no of childrens of " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;

            //create
            TreeNode<int> *childNode = new TreeNode<int>(childData);
            //push
            q.push(childNode);
            // Connection
            front->children.push_back(childNode);
        }
    }
}
void levelOrderPrint(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            cout << root->children[i]->data << " , ";
        }
        cout << endl;
        for (int i = 0; i < front->children.size(); i++)
        {
            q.push(front->children[i]);
        }
    }
}

int countNodes(TreeNode<int> *root)
{
    //edge case
    if (root == NULL)
        return 0;

    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return count;
}

int height(TreeNode<int> *root)
{
    //edge case
    if (root == NULL)
        return 0;
    int maxHeight = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = height(root->children[i]);
        if (childHeight >= maxHeight)
            maxHeight = childHeight;
    }
    //add +1 to max height to count root node also
    return maxHeight + 1;
}

void printNodesAtDepthK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printNodesAtDepthK(root->children[i], k - 1);
    }
}
int countLeafNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countLeafNodes(root->children[i]);
    }
    return count;
}
//first print root then children
void preOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preOrderTraversal(root->children[i]);
    }
}
// first print children then print root
void postOrderTraversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    //TreeNode<int> *root = takeInputUsingRecursion();
    TreeNode<int> *root = takeInputLevelWise();
    // levelOrderPrint(root);
    // cout << countNodes(root) << endl;
    // cout << height(root) << endl;
    // printNodesAtDepthK(root, 2);
    //cout << countLeafNodes(root) << endl;
    // preOrderTraversal(root);
    deleteTree(root);
    postOrderTraversal(root);
    return 0;
}