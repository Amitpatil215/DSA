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

bool isCycleDetectedDFS(int startNode, vector<bool>& visited,
                        vector<bool>& DfsVisited, vector<int> adjList[]) {
    visited[startNode] = true;
    DfsVisited[startNode] = true;

    for (auto nbr : adjList[startNode]) {
        if (!visited[nbr]) {
            bool hadCycle =
                isCycleDetectedDFS(nbr, visited, DfsVisited, adjList);
            // if in case we got a cycle then return
            if (hadCycle) return true;
        } else {
            // if it is alredy visited and it is also in the current dfs call
            // then we have got a cycle
            if (DfsVisited[nbr] == true) {
                return true;
            }
        }
    }
    // if we are done with current DFS call for this node
    // then will flag as false in DfsVisited array
    DfsVisited[startNode] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    vector<int> adjList[n + 1];  // one based indexing
    // adjacency List
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> DfsVisited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (isCycleDetectedDFS(i, visited, DfsVisited, adjList)) {
                return true;
            }
        }
    }
    return false;
}