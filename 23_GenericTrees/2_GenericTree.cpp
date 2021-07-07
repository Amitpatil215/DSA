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
int main()
{
    //TreeNode<int> *root = takeInputUsingRecursion();
    TreeNode<int> *root = takeInputLevelWise();
    levelOrderPrint(root);
    return 0;
}