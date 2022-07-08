/*
Detect Cycle In A Directed Graph

venice 64

Problem Statement
You are given a directed graph having ‘N’ nodes. A matrix ‘EDGES’ of size M x 2
is given which represents the ‘M’ edges such that there is an edge directed from
node EDGES[i][0] to node EDGES[i][1]. Find whether the graph contains a cycle or
not, return true if a cycle is present in the given directed graph else return
false.

Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(100,N(N-1)/2)
1 <= EDGES[i][0], EDGES[i][1] <= N
Where ‘T’ is the number of test cases.
Time Limit: 1 sec

Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3

Sample Output 1 :
true
Explanation For Input 1 :
The given graph contains cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
Sample Input 2 :
2
5
4
1 2
2 3
3 4
4 5
2
1
1 2

Sample Output 2 :
false
false
Explanation For Input 2 :
The given graphs don’t contain any cycle.

 */

#include <bits/stdc++.h>
int bfs(vector<int> &indegree, vector<int> adjList[]) {
    int size = 0;
    queue<int> q;
    // push all the nodes having having indegree 0 in the
    for (int node = 1; node < indegree.size(); node++) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        size++;

        // iterate over adj nodes, reduce indegree by 1. if zero then push to
        // queue
        for (auto nbr : adjList[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    return size;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // build an adjacency list
    vector<int> adjList[n + 1];  // node starting from 1 to n
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }
    // calculate indegree
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (auto nbr : adjList[i]) {
            indegree[nbr]++;
        }
    }

    // ans stores topological sort
    int sizeOfTopoSort;

    sizeOfTopoSort = bfs(indegree, adjList);

    // if we have a size of topological size equal to no of nodes then
    // we dont have any cycle
    if (sizeOfTopoSort == n) {
        return false;
    } else {
        return true;
    }
}
