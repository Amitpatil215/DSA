//**** For finding wheter a scc exist or not ****
/*

vencie 78
https://techiedelight.com/practice/?problem=IsStronglyConnectedGraph

Given a directed graph, determine whether it is strongly connected or
not. A directed graph is said to be strongly connected if every vertex
is reachable from every other vertex.

Input: Graph [edges = [(0, 1), (1, 2), (2, 0)], n = 3]
Output: true

Input: Graph [edges = [(0, 1), (1, 2), (0, 2)], n = 3]
Output: false

Input: Graph [edges = [(0, 1)], n = 2]
Output: false

Constraints:

• The graph is implemented using an adjacency list.
• The maximum number of nodes in the graph is 100, i.e., 0 <= n < 100,
and each node is represented by its numeric value.

*/

class Solution {
   public:
    /*
            /// Definition for a Graph
            class Graph
            {
            public:
                    /// vector of vectors to represent an adjacency list
                    vector<vector<int>> adjList;

                    /// Total number of nodes in the graph
                    int n;
            }
    */
    void dfsForPrintingSCC(int startNode, vector<bool> &visited,
                           vector<int> &component,
                           vector<vector<int>> &adjList) {
        visited[startNode] = true;
        component.push_back(startNode);
        for (auto nbr : adjList[startNode]) {
            if (!visited[nbr]) {
                dfsForPrintingSCC(nbr, visited, topoStack, adjList);
            }
        }
    }

    void dfs(int startNode, vector<bool> &visited, stack<int> &topoStack,
             vector<vector<int>> &adjList) {
        visited[startNode] = true;
        for (auto nbr : adjList[startNode]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, topoStack, adjList);
            }
        }
        topoStack.push(startNode);
    }

    bool isStronglyConnected(Graph const &graph) {
        int n = graph.n;
        vector<vector<int>> adjList = graph.adjList;

        // find topological sort
        stack<int> topoStack;
        vector<bool> visited(n, false);

        dfs(0, visited, topoStack, adjList);

        // check whether if we have left any node unvisited then
        // there must be a more than one component exists
        for (auto m : visited) {
            if (m == false) {
                return false;
            }
        }

        vector<vector<int>> reversedAdjList(n);
        // Reverse all the edges direction
        for (int i = 0; i < n; i++) {
            for (auto nbr : adjList[i]) {
                int u = i;
                int v = nbr;
                reversedAdjList[v].push_back(u);
            }
        }

        // now again check for dfs if in one iteration
        // we can visit all the nodes then it is SCC

        // mark all unvisited again
        fill(visited.begin(), visited.end(), false);

        //! -----------  Code for checking if SCC exist or not START------------
        // again do a dfs traversal
        dfs(0, visited, topoStack, reversedAdjList);

        // check whether if we have left any node unvisited then
        // there must be a more than one component exists
        for (auto m : visited) {
            if (m == false) {
                return false;
            }
        }
        return true;

        //! -----------  Code for checking if SCC exist or not END------------
    }
};

//** for printing every SCC ***********

class Solution {
   public:
    /*
            // Definition for a Graph
            class Graph
            {
            public:
                    // vector of vectors to represent an adjacency list
                    vector<vector<int>> adjList;

                    // Total number of nodes in the graph
                    int n;
            }
    */
    void dfsForPrintingSCC(int startNode, vector<bool> &visited,
                           vector<int> &component,
                           vector<vector<int>> &adjList) {
        visited[startNode] = true;
        component.push_back(startNode);
        for (auto nbr : adjList[startNode]) {
            if (!visited[nbr]) {
                dfsForPrintingSCC(nbr, visited, component, adjList);
            }
        }
    }

    void dfs(int startNode, vector<bool> &visited, stack<int> &topoStack,
             vector<vector<int>> &adjList) {
        visited[startNode] = true;
        for (auto nbr : adjList[startNode]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, topoStack, adjList);
            }
        }
        topoStack.push(startNode);
    }

    bool isStronglyConnected(Graph const &graph) {
        int n = graph.n;
        vector<vector<int>> adjList = graph.adjList;

        // find topological sort
        stack<int> topoStack;
        vector<bool> visited(n, false);

        dfs(0, visited, topoStack, adjList);

        // check whether if we have left any node unvisited then
        // there must be a more than one component exists
        for (auto m : visited) {
            if (m == false) {
                return false;
            }
        }

        vector<vector<int>> reversedAdjList(n);
        // Reverse all the edges direction
        for (int i = 0; i < n; i++) {
            for (auto nbr : adjList[i]) {
                int u = i;
                int v = nbr;
                reversedAdjList[v].push_back(u);
            }
        }

        // now again check for dfs if in one iteration
        // we can visit all the nodes then it is SCC

        // mark all unvisited again
        fill(visited.begin(), visited.end(), false);

        //! -----------  Code for printing all the conected components SATRT---
        vector<vector<int>> allConectedComponents;
        while (!topoStack.empty()) {
            int topNode = topoStack.top();
            vector<int> component;
            dfsForPrintingSCC(topNode, visited, component, reversedAdjList);
            allConectedComponents.push_back(component);
        }
        //! -----------  Code for printing all the conected components END----

        return true;
    }
};
