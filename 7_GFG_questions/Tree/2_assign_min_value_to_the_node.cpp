
/*

Job-A-Thon 12: Hiring Challenge | Practice
https://practice.geeksforgeeks.org/contest/job-a-thon-12-hiring-challenge/problems/#
Optimal Value

Accuracy: 47.92% Submissions: 2513 Points: 40

You are given a tree of N nodes rooted at node 1. The tree is given in form of
an array where Pi denotes the parent of the i-th node. Also, P1 = -1 as 1 is the
root node. You need to assign non-negative values to each node of the tree in a
manner such that it follows the following condition:

Let A denote the value assigned to a node and B represent the sum of values
assigned to the children of the node. Then, the following condition should
always hold, B ≤ A. Note that the root can be assigned any non-negative value.

You're also given an integer X. You need to assign values in such a way that
their sum is greater than or equal to X. Find the minimum value which needs to
be assigned to the root of the tree.

Example 1:

Input:
N = 4, X = 7,
P = [-1,1,2,3]
Output:
2
Explanation:
One possible solution is:
  1 (2)
  |
  2 (2)
  |
  3 (2)
  |
  4 (1)

Example 2:

Input:
N = 4, X = 10,
P = [-1,1,2,1]
Output:
4
Explanation:
One possible solution is:
        1 (4)
      /   \
 (2) 2     4 (2)
     |
 (2) 3

Your Task:
You don't need to read input or print anything. Your task is to complete the
function optimalValue() which takes two integers N, X and an array P as input
parameters and returns the minimum value which can be assigned to the root node.


Constraints:
1 ≤ N ≤ 2x104
1 ≤ X ≤ 109
1 ≤ Pi ≤ N


 */

/*
Approach : find height of the tree and divide it with x value

Intution: 
lets say at level 1 you gave k amount
then at level 2 you again need to give k or less than that to make sum k 
then at level 3 you again need to give k or less than that to make sum k
..and so on

this way if i give totalSum i.e. x divied by total no of levels i will get
minimum value to be assigned at each level which is the answer
 */

class Solution {
   public:
    int dfs(int node, vector<int> &dist, vector<int> adjList[]) {
        for (auto nbr : adjList[node]) {
            dist[nbr] = dist[node] + 1;
            dfs(nbr, dist, adjList);
        }
    }

    int optimalValue(int n, int x, vector<int> &p) {
        vector<int> adjList[n + 1];
        int root = -1;

        // generate adjList for the tree
        for (int i = 0; i < n; i++) {
            int parent = p[i];
            int child = i + 1;
            if (parent == -1)
                root = child;
            else {
                adjList[parent].push_back(child);
            }
        }

        // perform dfs and find dist to reach every node from root node

        vector<int> dist(n + 1, 0);
        // mark height of the root as 1
        dist[root] = 1;

        dfs(root, dist, adjList);
        int maxHeight = *max_element(dist.begin(), dist.end());
        // find ceil of x / maxHeight ;
        // ciel == (denominator +numerator -1) / denominator;
        int ans = (x + maxHeight - 1) / maxHeight;
        return ans;
    }
};