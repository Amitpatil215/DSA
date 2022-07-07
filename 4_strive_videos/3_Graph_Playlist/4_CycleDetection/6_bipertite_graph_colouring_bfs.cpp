/*
Bipertite Graph Colouring BFS

venice 61

Given an adjacency list of a graph adj  of V no. of vertices having 0 based
index. Check whether the graph is bipartite or not.


Example 1:

Input:

Output: 1
Explanation: The given graph can be colored
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored
in two colors such that color of adjacent
vertices differs.


Your Task:
You don't need to read or print anything. Your task is to complete the function
isBipartite() which takes V denoting no. of vertices and adj denoting adjacency
list of the graph and returns a boolean value true if the graph is bipartite
otherwise returns false.


Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isBipartiteBFS(int startNode, vector<int> adj[],
                        vector<int>& colours) {
        queue<int> q;

        q.push(startNode);
        colours[startNode] = 0;  // 0 ->Blue 1-> Green

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto nbr : adj[front]) {
                if (colours[nbr] == -1) {
                    // node is not eralier visited i.e coloured
                    // colour with opposite colour
                    // if parents colour is 1 then assign 0 otherwise 1
                    colours[nbr] = colours[front] == 1 ? 0 : 1;
                    q.push(nbr);
                } else {
                    // if alredy coloured then
                    // check if it has different colour than parent
                    // otherwise return false as we cant form a bipertite graph
                    if (colours[nbr] == colours[front]) {
                        return false;
                    }
                }
            }
        }
        // if we able to colour component without any adjacent same colours
        // then we have a bipertite graph
        return true;
    }

    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> colours(V, -1);
        for (int i = 0; i < V; i++) {
            if (colours[i] == -1) {
                if (!isBipartiteBFS(i, adj, colours)) {
                    return false;
                }
            }
        }
        return true;
    }
};
