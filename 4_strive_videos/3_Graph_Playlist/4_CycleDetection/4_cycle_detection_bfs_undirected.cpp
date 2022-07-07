/*
Detect Cycle in an Undirected Graph

venice 59

Problem Statement
Given a undirected graph of V vertices and E edges. Check whether the graph
contains a cycle or not. You should print "True" if the given graph contains at
least one cycle, else print "False". Note: There are no self-loops(an edge
connecting the vertice to itself) in the given graph. Input Format: The first
line of input will contain three integers V, E, and S, separated by a single
space.

From the second line onwards, the next 'E' lines will denote the edge of the
graphs.

Every edge is defined by two single space-separated integers 'a' and 'b', which
signifies an edge between vertice 'a' and vertice 'b'. Output Format: The single
line contains an string, "True" if cycle exists, else "False". Constraints: 1 <=
V <= 10^5 0 <= E <= 2 * 10^5 0 <= u,v < V

Time Limit: 1sec
Sample Input 1:
4 4
0 1
1 2
2 3
3 0
Sample Output 1:
True
Explanation For Sample Input 1:
From node 0 we can reach 0 again by following this sequence of nodes in the
path: 0,1,2,3,0.

Similarly from any of the node we can reach again to that node by following a
path. The graph in itself is a cycle. Sample Input 2: 5 3 0 1 1 2 3 4 Sample
Output 2: False
 */

#include <bits/stdc++.h>
using namespace std;
bool isCycleDetectedBFS(int startIndex, vector<bool> &visited,
                        vector<int> adjList[]) {
    // queue of node and parent
    queue<pair<int, int>> q;
    q.push({startIndex, -1});

    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        int node = front.first;
        int parent = front.second;

        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, node});
            } else {
                // if it is alredy visited and its parent is different
                // then we found a cycle
                if (nbr != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adjList[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(V);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (isCycleDetectedBFS(i, visited, adjList)) {
                cout << "True" << endl;
                return 0;
            };
        }
    }
    cout << "False" << endl;
    return 0;
}
