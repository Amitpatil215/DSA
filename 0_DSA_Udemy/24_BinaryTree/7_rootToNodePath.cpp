#include "1_BinaryTree.cpp"

bool getPath(BTNode<int> *root, int k, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (k == root->data)
    {
        return true;
    }
    bool isFoundInLeftSubTree = getPath(root->left, k, path);
    bool isFoundInRightSubTree = getPath(root->right, k, path);
    if (isFoundInLeftSubTree || isFoundInRightSubTree)
    {
        return true;
    }
    else
    {
        path.pop_back();
        return false;
    }
}

int main()
{
    BTNode<int> *root = takeInputLevelWise();
    vector<int> path;
    int searchNode = 3;
    if (getPath(root, searchNode, path))
    {

        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    else
    {
        cout << "No path found";
    }
}