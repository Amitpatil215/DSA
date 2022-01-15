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
    void bfs(int src)
    {
        queue<int> q;
        bool *visited = new bool[V]{false};

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int currNode = q.front();
            cout << currNode << endl;
            q.pop();
            // push all the nebhours of current node
            for (auto node : l[currNode])
            {
                if (!visited[node])
                {
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g(7);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.addEdge(4,5);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.bfs(1);
    return 0;
}