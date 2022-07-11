/*
Bridge

venice 75

https://techiedelight.com/practice/?problem=BridgesInGraph


Given an undirected connected graph, return a set of all bridges in the graph. A
bridge is an edge of a graph whose removal disconnects the graph.

Input: Graph [edges = [(0, 1), (1, 2), (2, 3)], n = 4]
Output: {(0, 1), (1, 2), (2, 3)}
Explanation: The graph has 3 bridges {(0, 1), (1, 2), (2, 3)}, since removal of
any of it disconnects the graph.

Input: Graph [edges = [(0, 1), (1, 2), (2, 3), (3, 0)], n = 4]
Output: {}
Explanation: The graph is 2–edge connected. i.e., it remains connected on
removal of any edge.

Note: The solution should return edges in increasing order of node's value. For
instance, both (1, 2) and (2, 1) represent the same edge in an undirected graph.
The solution should return edge (1, 2).

Constraints:

• The graph is implemented using an adjacency list.
• The maximum number of nodes in the graph is 100, i.e., 0 <= n < 100, and each
node is represented by its numeric value. • The graph is connected, i.e., every
node can be reached starting from all other nodes.

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

    void dfs(int startNode, int parent, int timer, vector<bool> &visited,
             vector<int> &startTime, vector<int> &lowTime,
             set<pair<int, int>> &ans, vector<vector<int>> adjList) {
        visited[startNode] = true;
        timer++;
        // intially mark starttime and low time both to the timer
        startTime[startNode] = lowTime[startNode] = timer;

        for (auto nbr : adjList[startNode]) {
            if (!visited[nbr]) {
                dfs(nbr, startNode, timer, visited, startTime, lowTime, ans,
                    adjList);
                // take minimum low time from the adjacent nodes
                // and assign it to current startNode
                lowTime[startNode] = min(lowTime[startNode], lowTime[nbr]);

                // if in case we find that our startNode start time is less
                // than low time of its neighbour then we got a bridge
                if (startTime[startNode] < lowTime[nbr]) {
                    ans.insert({startNode, nbr});
                }
            } else {
                // we shouldn't consider parent
                if (nbr != parent) {
                    lowTime[startNode] =
                        min(lowTime[startNode], startTime[nbr]);
                }
            }
        }
    }

    set<pair<int, int>> findBridges(Graph const &graph) {
        int n = graph.n;
        vector<bool> visited(n, false);
        vector<int> startTime(n, 0);
        vector<int> lowTime(n, 0);

        set<pair<int, int>> ans;
        // for all components
        for (int i = 0; i < n; i++) {
            dfs(i, -1, 0, visited, startTime, lowTime, ans, graph.adjList);
        }
        return ans;
    }
};
