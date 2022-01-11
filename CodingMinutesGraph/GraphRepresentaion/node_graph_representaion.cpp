#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
using namespace std;

class Node
{
public:
    string name;
    list<string> nbrs;
    Node(string name)
    {
        this->name = name;
    }
};

class Graph
{
    unordered_map<string, Node *> m;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
        {
            m[city] = new Node(city);
        }
    }

    void addEdge(string src, string dst, bool isUndir = false)
    {
        m[src]->nbrs.push_back(dst);

        if (isUndir)
        {
            m[dst]->nbrs.push_back(src);
        }
    }

    void printAdjList()
    {
        for (auto cityPair : m)
        {
            string name = cityPair.first;
            Node *Nodes = cityPair.second;

            cout << name << " --> ";
            for (auto connectedCity : Nodes->nbrs)
            {
                cout << " " << connectedCity;
            }
            cout << endl;
        }
    }
};
int main()
{

    vector<string> cities = {"Delhi", "Mumbai", "Kolkatta", "Pune"};
    Graph G(cities);
    G.addEdge("Delhi", "Mumbai");
    G.addEdge("Mumbai", "Kolkatta");
    G.addEdge("Mumbai", "Delhi");
    G.addEdge( "Kolkatta", "Pune");
    G.printAdjList();
    return 0;
}