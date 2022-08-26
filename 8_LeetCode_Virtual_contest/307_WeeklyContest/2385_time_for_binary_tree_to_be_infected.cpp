/*
2385. Amount of Time for Binary Tree to Be Infected
User Accepted:4282
User Tried:5498
Total Accepted:4416
Total Submissions:8725
Difficulty:Medium
You are given the root of a binary tree with unique values, and an integer
start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.



Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.


Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// intuion is to convert to graph and apply bfs
// similar question as rotten eggs
// as we do not know number of node use map instead of vector<int>adjList ;)
class Solution {
   public:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, int> dist;
    unordered_map<int, bool> visited;
    void bfsInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            if (front->left) {
                q.push(front->left);
                adjList[front->val].push_back(front->left->val);
                adjList[front->left->val].push_back(front->val);
            };
            if (front->right) {
                q.push(front->right);
                adjList[front->val].push_back(front->right->val);
                adjList[front->right->val].push_back(front->val);
            };
        }
    }
    void bfsInGraph(int src) {
        visited[src] = true;
        queue<int> q;
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            for (auto nbr : adjList[front]) {
                if (!visited[nbr]) {
                    dist[nbr] = dist[front] + 1;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        // convert tree to graph
        bfsInTree(root);

        bfsInGraph(start);
        int time = 0;
        for (auto t : dist) {
            time = max(time, t.second);
        }
        return time;
    }
};