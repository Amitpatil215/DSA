#include <iostream>
#include <list>
#include <vector>

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
    bool dfs(
        int node, int parent, vector<bool> &visitedArray)
    {
        visitedArray[node] = true;

        bool isContainCycle = false;

        for (auto nbr : l[node])
        {
            if (!visitedArray[nbr])
            {
                bool isNbrFoundCycle = dfs(nbr, node, visitedArray);
                if (isNbrFoundCycle)
                    return true;
            }
            // this neighbour is alredy visited but it is not a parent of current node
            // that means it makes a cycle
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool contains_cycle()
    {
        // logic
        // Keep track of visited nodes
        // cycle present if we can visit a node more than once
        // and that node is not the parent of the current node

        vector<bool> visitedArray(V, false);
        bool isContainCycle = dfs(0, 0, visitedArray);
        return isContainCycle;
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    // g.addEdge(2, 0);

    cout << g.contains_cycle();
    return 0;
}