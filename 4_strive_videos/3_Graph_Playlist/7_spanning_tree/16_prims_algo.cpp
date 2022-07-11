/*
Minimum sppanning tree Prims algo
venice 72
https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

Given a weighted, undirected and connected graph of V vertices and E edges. The
task is to find the sum of weights of the edges of the Minimum Spanning Tree.



Example 1:

Input:

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.


Your task:
Since this is a functional problem you don't have to worry about input, you just
have to complete the function  spanningTree() which takes number of vertices V
and an adjacency matrix adj as input parameters and returns an integer denoting
the sum of weights of the edges of the Minimum Spanning Tree.

Here adj[i] contains a list of lists containing two integers where the first
integer a[i][0] denotes that there is an edge between i and a[i][0] and second
integer a[i][1] denotes that the distance between edge i and a[i][0] is a[i][1].

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).


Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
Graph is connected and doesn't contain self loops & multiple edges.
*/
class Solution {
   public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> edges[]) {
        // build adjacecny list
        vector<pair<int, int>> adjList[v];

        for (int i = 0; i < v; i++) {
            for (auto edge : edges[i]) {
                adjList[i].push_back({edge[0], edge[1]});
                adjList[edge[0]].push_back({i, edge[1]});
            }
        }

        // perform prims algo
        vector<int> dist(v, INT_MAX);
        vector<bool> mst(v, false);
        vector<int> parent(v, -1);

        dist[0] = 0;
        // as we gonna be having v-1 edges iterate for that no of times
        for (int i = 0; i < v - 1; i++) {
            // choose minimum dist from dist array and which
            //  is not yet considered in mst
            int minDist = INT_MAX;
            int minNode = -1;
            for (int i = 0; i < v; i++) {
                if (!mst[i] && minDist > dist[i]) {
                    minDist = dist[i];
                    minNode = i;
                    // cout<<minDist<<endl;
                }
            }

            // consider min node as mst
            mst[minNode] = true;

            // update the distance for its neighbours
            for (auto nbr : adjList[minNode]) {
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;
                if (!mst[nbrNode] && nbrWeight < dist[nbrNode]) {
                    dist[nbrNode] = nbrWeight;
                    parent[nbrNode] = minNode;
                }
            }
        }
        // print edges
        // for(int i=1;i< v; i++){
        //     cout<<parent[i]<<"-"<<i <<"  "<<dist[i]<<endl;
        // }
        // cout<<endl;

        // find sum of weight
        int sum = 0;
        for (auto w : dist) {
            sum += w;
        }
        return sum;
    }
};

//! Priotiy Queue approach

class Solution {
   public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> edges[]) {
        // build adjacecny list
        vector<pair<int, int>> adjList[v];

        for (int i = 0; i < v; i++) {
            for (auto edge : edges[i]) {
                adjList[i].push_back({edge[0], edge[1]});
                adjList[edge[0]].push_back({i, edge[1]});
            }
        }

        // perform prims algo
        vector<int> dist(v, INT_MAX);
        vector<bool> mst(v, false);
        vector<int> parent(v, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minpq;

        dist[0] = 0;
        minpq.push({0, 0});
        // as we gonna be having v-1 edges iterate for that no of times
        while (!minpq.empty()) {
            // choose minimum dist from dist array
            int minNode = minpq.top().second;

            minpq.pop();
            // consider min node as mst
            mst[minNode] = true;

            // update the distance for its neighbours
            for (auto nbr : adjList[minNode]) {
                int nbrNode = nbr.first;
                int nbrWeight = nbr.second;
                if (!mst[nbrNode] && nbrWeight < dist[nbrNode]) {
                    dist[nbrNode] = nbrWeight;
                    parent[nbrNode] = minNode;
                    minpq.push({nbrWeight, nbrNode});
                }
            }
        }
        // print edges
        // for(int i=1;i< v; i++){
        //     cout<<parent[i]<<"-"<<i <<"  "<<dist[i]<<endl;
        // }
        // cout<<endl;

        // find sum of weight
        int sum = 0;
        for (auto w : dist) {
            sum += w;
        }
        return sum;
    }
};
