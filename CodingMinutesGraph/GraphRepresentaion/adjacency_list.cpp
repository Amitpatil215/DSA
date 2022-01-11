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
            cout<<endl;
        }
    }
};

int main()
{
    Graph G(6);
    G.addEdge(0, 1);
    G.addEdge(0, 4);
    G.addEdge(2, 1);
    G.addEdge(3, 4);
    G.addEdge(4, 5);
    G.addEdge(2, 3);
    G.addEdge(3, 5);
    G.print();
    return 0;
}