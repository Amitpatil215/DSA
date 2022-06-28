#include <bits/stdc++.h>
using namespace std;
// Adjacency Matrix
// venice 57
/*
Input
6 9 /// node and edges
0 4
0 3
1 2
1 4
1 5
2 3
2 5
5 3
5 4

 */

int main() {
    int n, m;
    // n -> no of nodes of the graph
    // m -> no of edges in the graph
    cin >> n >> m;
    int adj[n + 1][n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// Adjacency List
int main() {
    int n, m;
    // n -> no of nodes of the graph
    // m -> no of edges in the graph
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}