#include <iostream>
#include <list>
#include <queue>
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

    void addEdge(int src, int dst, bool isUndir = true)
    {
        l[src].push_back(dst);

        if (isUndir)
        {
            l[dst].push_back(src);
        }
    }

    void print()
    {
        // Iterating over a list of adjacency lists
        for (int i = 0; i < V; i++)
        {
            cout << " " << i << " --> ";
            for (auto eachList : l[i])
            {
                cout << " " << eachList;
            }
            cout << endl;
        }
    }
    void bfs(int src, int dst = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{false};
        int *parent = new int[V]{0};
        int *distance = new int[V]{0};

        q.push(src);
        visited[src] = true;
        parent[src] = src;
        distance[src] = 0;

        while (!q.empty())
        {
            int currNode = q.front();
            q.pop();
            // push all the nebhours of current node
            for (auto node : l[currNode])
            {
                if (!visited[node])
                {
                    q.push(node);
                    parent[node] = currNode;
                    distance[node] = distance[currNode] + 1;
                    visited[node] = true;
                }
            }
        }

        // Get the distance of every node from the source node
        for (int i = 0; i < V; i++)
        {
            cout << "Shortest distance to node " << i << " is " << distance[i] << endl;
        }

        // get shortest path between source and destination
        if (dst != -1)
        {
            int temp = dst;
            cout << dst;
            while (temp != src)
            {
                int par = parent[temp];
                cout << "-->" << par;
                temp = par;
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
    g.bfs(1, 6);
    return 0;
}