/* 
Method 1
// if graph has a cycle and no of nodes are odd then the graph id bipartite
 */

#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<bool> &visited, vector<int> adj[])
{

    // if the node is alredy visited and it is not its parent that means we got a cycle
    if (visited[node] && node != parent)
    {
        return true;
    }

    visited[node] = true;

    for (auto nbr : adj[node])
    {
        // we shouldn't go back as it is undirected graph
        if (nbr != parent)
        {
            // perform DFS on nbrs and find out does they contain any cycle
            bool nbrComponentHasCycle = dfs(nbr, node, visited, adj);
            if (nbrComponentHasCycle)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    // n-> no of vertices
    // m-> no of edges

    n = 3;
    m = 2;

    vector<int> adj[n];
    // // while (m--)
    // // {
    // //     int src, dst;
    // //     cin >> src >> dst;

    // //     adj[src].push_back(dst);
    // //     adj[dst].push_back(src);
    // // }

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(0);
    adj[2].push_back(1);
    adj[0].push_back(2);

    vector<bool> visited(n, false);
    int src = 0;
    int parent = -1;

    bool isContainCycle = dfs(src, parent, visited, adj);

    // if graph has a cycle and no of nodes are odd then the graph id bipartite
    if (isContainCycle && n % 2 != 0)
    {
        cout << "Bipartite Grpah";
    }
    else
    {
        cout << "Non-Bipartite Grpah";
    }
    return 0;
}