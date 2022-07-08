/*
Topological Sort using BFS | Kahn's algorithm

venice 66

refer for que -> to 10_topological sort using bfs 

 */
#include <bits/stdc++.h>
vector<int> bfs(vector<int> &indegree, vector<int> adjList[]) {
    vector<int> ans;
    queue<int> q;
    // push all the nodes having having indegree 0 in the
    for (int node = 0; node < indegree.size(); node++) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        // iterate over adj nodes, reduce indegree by 1. if zero then push to
        // queue
        for (auto nbr : adjList[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    return ans;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // build an adjacency list
    vector<int> adjList[v];  // node starting from 1 to n
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
    }
    // calculate indegree
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto nbr : adjList[i]) {
            indegree[nbr]++;
        }
    }

    // ans stores topological sort
    vector<int> topSort;

    topSort = bfs(indegree, adjList);

    return topSort;
}