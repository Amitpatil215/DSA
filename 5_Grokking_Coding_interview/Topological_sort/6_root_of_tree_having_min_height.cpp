/*
Roots of the tree having minimum height

https://www.codingninjas.com/codestudio/problems/roots-of-the-tree-having-minimum-height-_1235193?leftPanelTab=0


Sample Input 1:
2
3
1 2
2 3
4
1 2
3 1
4 1
Sample Output 1:
2
1
Explanation For Sample Input 1:
For the first test case, if we root the tree at Node 2, the height of the
resultant tree is 1 which is the minimum possible height. For the second test
case, if we root the tree at Node 1, the height of the resultant tree is 1 which
is the minimum possible height. Sample Input 2:
2
4
1 3
2 3
4 2
2
1 2
Sample Output 2:
2 3
1 2
 */
#include <bits/stdc++.h>
vector<int> minHeightRoots(vector<vector<int>> &edges) {
    vector<int> minHeightRoots;
    cout << "size->" << edges.size() << endl;
    if (edges.size() == 0) return minHeightRoots;

    // if there is only one node present then that node should be
    // int our result
    if (edges.size() == 1 && edges[0].size() == 0) {
        minHeightRoots.push_back(1);
        return minHeightRoots;
    }
    // tree has n-1 edges for n nodes
    int n = edges.size() + 1;
    // 1 based indexing
    vector<int> adjList[n + 1];
    vector<int> indegree(n + 1, 0);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
        indegree[u]++;
        indegree[v]++;
    }

    // push all the leaf nodes into the queue
    deque<int> leaves;

    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 1) {
            leaves.push_back(i);
        }
    }

    // discard leaves until we are left with one or two
    // nodes at the end
    int nodesCount = n;
    while (nodesCount > 2) {
        int leaveCount = leaves.size();
        nodesCount -= leaveCount;
        for (int i = 0; i < leaveCount; i++) {
            int front = leaves.front();
            leaves.pop_front();

            // reduce indegree of the neighbours
            for (auto nbr : adjList[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 1) {
                    leaves.push_back(nbr);
                }
            }
        }
    }
    move(leaves.begin(), leaves.end(), back_inserter(minHeightRoots));
    sort(minHeightRoots.begin(), minHeightRoots.end());
    return minHeightRoots;
}