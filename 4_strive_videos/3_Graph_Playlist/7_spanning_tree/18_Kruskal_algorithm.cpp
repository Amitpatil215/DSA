/* Minimum Spanning Tree

venice 74

https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1#

This problem is part of GFG SDE Sheet. Click here to view more.
Given a weighted, undirected and connected graph of V vertices and E edges. The
task is to find the sum of weights of the edges of the Minimum Spanning Tree.



Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

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

class disjoint_set {
   private:
    int n;
    vector<int> Parent;
    vector<int> Rank;

    void initilaize_parent() {
        for (int i = 0; i < n; i++) {
            Parent[i] = i;
        }
    }

   public:
    // constructor
    disjoint_set(int n) {
        this->n = n;
        Parent = vector<int>(n);
        initilaize_parent();
        Rank = vector<int>(n, 0);
    }

    int find_parent(int node) {
        if (Parent[node] == node) {
            return node;
        }

        // find parent recursively until the node is a parent of himself
        // and also a Path compression step
        return Parent[node] = find_parent(Parent[node]);
    }

    void union_sets(int u, int v) {
        // find parent of u and v
        u = find_parent(u);
        v = find_parent(v);

        // we attach to a node having higher rank
        // if rank is same then increase rank of any one of the
        // parent node and attach to it
        if (Rank[u] < Rank[v]) {
            Parent[u] = v;
        } else if (Rank[u] > Rank[v]) {
            Parent[v] = u;
        } else {
            Rank[u]++;
            Parent[v] = u;
        }
    }
};

bool comp(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];  // sort according to weight
}

class Solution {
   public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[]) {
        // build an edge list not adjacency lsit
        vector<vector<int>> edgeList;
        for (int i = 0; i < v; i++) {
            for (auto x : adj[i]) {
                vector<int> edge(3);
                edge[0] = i;     // source
                edge[1] = x[0];  // destination
                edge[2] = x[1];  // weight
                edgeList.push_back(edge);
            }
        }

        // cout<<edgeList.size()<<endl;
        // sort according to weight to pick greedly
        sort(edgeList.begin(), edgeList.end(), comp);

        // pick edge with least weight
        // if they belong to different set then exclude
        // other wise consider in min spanning tree
        int cost = 0;

        disjoint_set ds = disjoint_set(v);

        for (auto edge : edgeList) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (ds.find_parent(u) != ds.find_parent(v)) {
                cost += wt;
                ds.union_sets(u, v);
            }
        }
        return cost;
    }
};
