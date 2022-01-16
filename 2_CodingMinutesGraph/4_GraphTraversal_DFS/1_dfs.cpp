#include <iostream>
#include <list>

using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int src, int dst, bool undir = true)
    {
        l[src].push_back(dst);
        if (undir)
        {
            l[dst].push_back(src);
        }
    }

    void dfs(int src)
    {
        bool *visitedArray = new bool[V]{false};
        dfsHelper(src, visitedArray);
    }

    void dfsHelper(int node, bool *visitedArray)
    {
        // mark node is visited
        visitedArray[node] = true;
        cout << node << " --> ";

        // and depth first search on every nebhour
        for (auto nbr : l[node])
        {
            // only search if that node is not visited erlier
            if (!visitedArray[nbr])
            {
                dfsHelper(nbr, visitedArray);
            }
        }
    }
};
int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.dfs(1);
    return 0;
}