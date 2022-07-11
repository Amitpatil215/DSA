/*

Dijikstra Algorithm Shortest path in undirected graph

venice 70

https://techiedelight.com/practice/?problem=SingleSourceShortestPaths

Given a weighted directed graph with non-negative edge weights and a source
vertex, return the shortest path cost from the source vertex to every other
reachable vertex in the graph.

Input: Graph [edges = [(0, 1, 10), (0, 4, 3), (1, 2, 2), (1, 4, 4), (2, 3, 9),
(3, 2, 7), (4, 1, 1), (4, 2, 8), (4, 3, 2)], n = 5], source = 0 Here, triplet
(x, y, w) represents an edge from x to y having weight w.

Output: {[0, 1, 4], [0, 2, 6], [0, 3, 5], [0, 4, 3]}
Here, triplet (s, d, c) indicates that the shortest path from source s to
destination d has cost c.

Explanation:

• Shortest path from (0 —> 1) is [0 —> 4 —> 1] with cost 4.
• Shortest path from (0 —> 2) is [0 —> 4 —> 1 —> 2] with cost 6.
• Shortest path from (0 —> 3) is [0 —> 4 —> 3] with cost 5.
• Shortest path from (0 —> 4) is [0 —> 4] with cost 3.

Input: Graph [edges = [(0, 1, 10), (0, 4, 3), (1, 2, 2), (1, 4, 4), (2, 3, 9),
(3, 2, 7), (4, 1, 1), (4, 2, 8), (4, 3, 2)], n = 5], source = 1 Output: {[1, 2,
2], [1, 3, 6], [1, 4, 4]} Explanation:

• Shortest path from (1 —> 0) does not exist.
• Shortest path from (1 —> 2) is [1 —> 2] with cost 2.
• Shortest path from (1 —> 3) is [1 —> 4 —> 3] with cost 6.
• Shortest path from (1 —> 4) is [1 —> 4] with cost 4.

Constraints:

• The graph is implemented using an adjacency list.
• The maximum number of nodes in the graph is 100, i.e., 0 <= n < 100, and each
node is represented by its numeric value. • The source vertex is among the set
of vertices in the graph.

*/

class Solution {
   public:
    /*
            /// Definition for an Edge
            class Edge {
            public:
                    int source, dest, weight;
            };

            /// Definition for a Graph
            class Graph
            {
            public:

                    /// vector of vectors to represent an adjacency list
                    vector<vector<pair<int,int>>> adjList;

                    /// total number of nodes in the graph
                    int n;

                    Graph(vector<Edge> &edges, int size)
                    {
                            n = size;
                            adjList.resize(n);

                            for (Edge &edge: edges) {
                                    adjList[edge.source].push_back(make_pair(edge.dest,
       edge.weight));
                            }
                    }
            };
    */

    set<vector<int>> findShortestPaths(Graph const &graph, int source) {
        set<vector<int>> paths;

        vector<vector<pair<int, int>>> adjList = graph.adjList;

        vector<int> dist(graph.n, INT_MAX);

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minpq;

        // push source node in the minpq and mark distance as 0
        dist[source] = 0;
        minpq.push({0, source});

        while (!minpq.empty()) {
            auto top = minpq.top();
            minpq.pop();
            int curNode = top.second;
            int wt = top.first;

            for (auto nbr : adjList[curNode]) {
                int nbrNode = nbr.first;
                int nbrDist = nbr.second;

                if (wt + nbrDist < dist[nbrNode]) {
                    dist[nbrNode] = wt + nbrDist;
                    minpq.push({dist[nbrNode], nbrNode});
                }
            }
        }

        for (int destination = 0; destination < dist.size(); destination++) {
            if (dist[destination] == INT_MAX || destination == source) continue;
            vector<int> NodeWithDist;
            NodeWithDist.push_back(source);
            NodeWithDist.push_back(destination);
            NodeWithDist.push_back(dist[destination]);

            paths.insert(NodeWithDist);
        }

        return paths;
    }
};
