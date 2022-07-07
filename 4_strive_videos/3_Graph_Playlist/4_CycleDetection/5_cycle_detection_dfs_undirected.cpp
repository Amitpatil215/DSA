/*

Cycle Detection using DFS in Undirected Graph

vecnice 61
for que refer 4_cycle_detection_bfs_undirected.cpp
 */

#include <bits/stdc++.h>
using namespace std;

bool detectCycleDFS(int startNode, int parentNode, vector<int>& visited,
                    vector<vector<int>>& adjList) {
    visited[startNode] = true;
    for (auto nbr : adjList[startNode]) {
        if (!visited[nbr]) {
            bool isCycleDetected =
                detectCycleDFS(nbr, startNode, visited, adjList);
            if (isCycleDetected) return true;
        } else {
            // if node is already visited and its not visited by its parent
            // then we have a cycle
            if (parentNode != -1 && nbr != parentNode) return true;
        }
    }
    return false;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjList(vertices, vector<int>());

    for (int i = 0; i < vertices; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // check dfs cycle for every component
    vector<int> visited(vertices, false);
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (detectCycleDFS(i, -1, visited, adjList)) {
                cout << "True" << endl;
                return 0;
            }
        }
    }
    cout << "False" << endl;

    return 0;
}
