/*
M-Coloring Problem

venice 85
MediumAccuracy: 47.46%Submissions: 49963Points: 4
Given an undirected graph and an integer M. The task is to determine if the
graph can be colored with at most M colors such that no two adjacent vertices of
the graph are colored with the same color. Here coloring of a graph means the
assignment of colors to all vertices. Print 1 if it is possible to colour
vertices and 0 otherwise.

Example 1:

Input:
N = 4
M = 3
E = 5
Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 1
Explanation: It is possible to colour the
given graph using 3 colours.
Example 2:

Input:
N = 3
M = 2
E = 3
Edges[] = {(0,1),(1,2),(0,2)}
Output: 0
Your Task:
Your task is to complete the function graphColoring() which takes the 2d-array
graph[], the number of colours and the number of nodes as inputs and returns
true if answer exists otherwise false. 1 is printed if the returned value is
true, 0 otherwise. The printing is done by the driver's code. Note: In Example
there are Edges not the graph.Graph will be like, if there is an edge between
vertex X and vertex Y graph[] will contain 1 at graph[X-1][Y-1], else 0. In
2d-array graph[ ], nodes are 0-based indexed, i.e. from 0 to N-1.Function will
be contain 2-D graph not the edges.

Expected Time Complexity: O(MN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 20
1 ≤ E ≤ (N*(N-1))/2
1 ≤ M ≤ N
 */

class Solution {
   public:
    bool isPossibleToColour(int node, int color, bool graph[101][101], int m,
                            int n, vector<int>& colors) {
        for (int nbr = 0; nbr < n; nbr++) {
            if (nbr != node && graph[node][nbr] == 1 && colors[nbr] == color) {
                return false;
            }
        }
        return true;
    }
    bool gc(int src, bool graph[101][101], int m, int n, vector<int>& colors) {
        if (src == n) {
            return true;
        }

        for (int color = 1; color <= m; color++) {
            if (isPossibleToColour(src, color, graph, m, n, colors)) {
                colors[src] = color;
                if (gc(src + 1, graph, m, n, colors)) return true;
                colors[src] = 0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours
    // such that no two adjacent vertices of graph are coloured with same
    // colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here

        vector<int> colors(n, 0);
        return gc(0, graph, m, n, colors);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends