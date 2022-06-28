/*
BFS
BFS in Graph

venice  58

Problem Statement
You are given an undirected and disconnected graph G(V, E) having V vertices
numbered from 0 to V-1 and E edges. Your task is to print its BFS traversal
starting from the 0th vertex. BFS or Breadth-First Traversal of a graph is an
algorithm used to visit all of the nodes of a given graph. In this traversal
algorithm, one node is selected, and then all of the adjacent nodes are visited
one by one. An undirected graph is a graph where all the edges are
bidirectional, i.e., they point from source to destination and destination to
source. A graph is disconnected if at least two vertices of the graph are not
connected by a path.

 Note:
1. Here, you need to consider that you need to print the BFS path starting from
vertex 0 only.
2. V is the number of vertices present in graph G, and all vertices are numbered
from 0 to V-1.
3. E is the number of edges present in graph G.
4. Graph input is provided as the number of vertices and a list of edges.
5. Handle for Disconnected Graphs as well.
For Example: Consider graph:

Here, starting from 0, it is connected to 1 and 2 so, BFS traversal from here
will be [0, 1, 2 ]. Now, 3 is also connected to 2. So, BFS traversal becomes [0,
1, 2, 3]. Note: For each node, the correct order of printing the connected nodes
will be sorted order, i.e., if {3,6,9,4} are connected to 1, then the correct
order of their printing is {1,3,4,6,9}.

Constraints :
0 <= V <= 10^4
0 <= E <= (V * (V - 1)) / 2
0 <= A <= V - 1
0 <= B <= V - 1

Where 'V' is the number of vertices, 'E' is the number of edges, 'A' and 'B' are
the vertex numbers. 
Time Limit: 1 second 

Sample Input 1: 4 4 0 1 0 3 1 2 2 3
Sample Output 1:
0 1 3 2
Explanation F
 */

#include <bits/stdc++.h>

void bfs(int startIndex, int vertex, vector<int> &ans, vector<vector<int>> adj,
         vector<int> &visited) {
    queue<int> q;
    q.push(startIndex);
    visited[startIndex] = 1;
    while (!q.empty()) {
        int frontNode = q.front();
        ans.push_back(frontNode);
        q.pop();

        // explore nodes neighbours
        sort(adj[frontNode].begin(),
             adj[frontNode]
                 .end());  // [optional] just to match to the test case answer
        for (auto nbr : adj[frontNode]) {
            if (visited[nbr] == 0) {
                q.push(nbr);
                visited[nbr] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    // build adjacency list
    vector<vector<int>> adj(vertex, vector<int>());
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Do BFS on components
    vector<int> visited(vertex, 0);
    vector<int> ans;
    for (int i = 0; i < vertex; i++) {
        // if not visited then bfs
        if (visited[i] == 0) {
            bfs(i, vertex, ans, adj, visited);
        }
    }
    return ans;
}