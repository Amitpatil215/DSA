

/*
Delete nodes greater than k
EasyAccuracy: 49.67%Submissions: 13319Points: 2
Given a BST and a value k, the task is to delete the nodes having values greater
than or equal to k.

Example 1:

Input:
    4
   / \
  1   9
k = 2
Output:
1
Your Task:
The task is to complete the function deleteNode() which takes root, k as the
argument, and returns the root of tree after deleting values greater than or
equal to k. The driver code will print the inorder traversal of the updated tree
in output itself.

Expected Time Complexity: O(Size of tree)
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= A[] <= 103
1 <= k <= N
 */

// } Driver Code Ends
/*The node structure
struct Node {
int data;
Node * right, * left;
};*/

/* 

Algorithm:

FUNCTION buildTree (root,X)
    IF (root==NULL)
        Return NULL;
    END IF
    IF (root->data is equal to X)
        return root->left; //returning the left subtree basically
    ELSE IF(root->data>key)
        ///recur for the left subtree since left subtree may also have nodes 
        ///that need to be deleted due to greater or equal values
        return buildTree(root->left, X); 
    ELSE
        ///root is not at all to be deleted, same for left subtree, 
        ///recursively process right subtree
        root->right=buildTree(root->right, X);
        return root;
END FUNCTION
 */


class Solution {
   public:
    /*The function should return the root of the modified tree*/
    Node *deleteNode(Node *root, int k) {
        if (root == NULL) {
            return NULL;
        }

        if (root->data == k) {
            return root->left;
        } else if (root->data > k) {
            return deleteNode(root->left, k);
        } else {
            root->right = deleteNode(root->right, k);
        }

        return root;
    }
};
