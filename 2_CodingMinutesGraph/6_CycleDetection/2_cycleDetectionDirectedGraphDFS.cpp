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
        int node, vector<bool> &visitedArray, vector<bool> &currCallStack)
    {
        // visit the node and add to current call satck
        visitedArray[node] = true;
        currCallStack[node] = true;

        // perform DFS on nbrs
        // if they are visited alredy then check in current call stack if present-> we found cycle otherwise no cycle
        for (auto nbr : l[node])
        {
            if (!visitedArray[nbr])
            {
                bool isContainCycle = dfs(nbr, visitedArray, currCallStack);
                // if any of the nbr found cycle
                if (isContainCycle)
                    return true;
            }
            else
            {
                if (currCallStack[nbr])
                {
                    // we found a cycle
                    return true;
                }
            }
        }
        // finally if there is no cycle found and we returning back from a node
        // pop out it from call stack
        currCallStack[node] = false;
        return false;
    }

    bool contains_cycle()
    {
        //logic
        // We have a cycle only if
        // 1. It is erlier visited
        // 2. and present in the current dfs call stack
        // (basically means a nbr is also a parent of the current node)
        // thats why we maintaining a currcallstack array to check
        vector<bool> visitedArray(V, false);
        vector<bool> currCallStack(V, false);
        bool isContainCycle = dfs(0, visitedArray, currCallStack);
        return isContainCycle;
    }
};

int main()
{
    Graph g(3);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 0, false);

    cout << g.contains_cycle();
    return 0;
}