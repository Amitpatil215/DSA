/*
DFS Traversal

venice 59

Problem Statement
Given an undirected and disconnected graph G(V, E), containing 'V' vertices and
'E' edges, the information about edges is given using 'GRAPH' matrix, where i-th
edge is between GRAPH[i][0] and GRAPH[i][1]. print its DFS traversal. V is the
number of vertices present in graph G and vertices are numbered from 0 to V-1.

E is the number of edges present in graph G.

Note :
The Graph may not be connected i.e there may exist multiple components in a
graph. 

Input Format : The first line of input will contain two Integers V and E,
separated by a single space.

From the second line onwards, the next 'E' lines will denote the undirected edge
of the graphs.

Every edge is defined by two single space-separated integers 'a' and 'b', which
signifies an edge between the vertices 'a' and 'b'. 

A component having a smaller first vertex in sorted order will come first.

Constraints :
2 <= V <= 10^3
1 <= E <= (5 * (10^3))

Time Limit: 1sec
Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4
Explanation For Sample Input 1:
If we do a DFS traversal from vertex 0 we will get a component with vertices [0,
2, 1]. If we do a DFS traversal from 3 we will get another component with
vertices [3, 4]

Hence,  we have two disconnected components so on the first line, print 2. Now,
print each component in increasing order. On the first line print 0 1 2 and on
the second line, print 3 4.

[0 1 2] comes before [3 4] as the first vertex 0 from the first component is
smaller than the first vertex 3 from the second component.
 */

void dfs(int startIndex, vector<vector<int>> &adjList, vector<int> &component,
         vector<bool> &visited) {
    component.push_back(startIndex);
    sort(adjList[startIndex].begin(), adjList[startIndex].end());
    for (auto nbr : adjList[startIndex]) {
        if (!visited[nbr]) {
            visited[nbr] = true;
            dfs(nbr, adjList, component, visited);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges) {
    // build adjacency list
    vector<vector<int>> adjList(V, vector<int>());
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<vector<int>> ans;
    // call DFS on components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = true;
            vector<int> component;
            dfs(i, adjList, component, visited);
            ans.push_back(component);
        }
    }
    return ans;
}