#include <bits/stdc++.h>
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

    int bfs(int src, int dst = -1)
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

        return distance[dst];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{

    vector<int> board(n + 1, 0);

    // Board to Graph Conversion
    // For Ladders
    for (auto l : ladders)
    {
        int start = l.first;
        int end = l.second;
        board[start] = end - start;
    }

    // For Snake
    for (auto s : snakes)
    {
        int start = s.first;
        int end = s.second;
        board[start] = end - start;
    }

    //Graph
    Graph g(n + 1);

    for (int src = 1; src < n; src++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int dest = src + dice;
            dest += board[dest];

            if (dest <= n)
            {
                g.addEdge(src, dest);
            }
        }
    }

    return g.bfs(1, n);
}

int main()
{
    int n = 36;
    vector<pair<int, int>> ladders = {{2, 15}, {5, 7}, {9, 27}, {18, 29}, {25, 35}};
    vector<pair<int, int>> snakes = {{17, 4}, {20, 6}, {34, 12}, {24, 16}, {32, 30}};
    cout << min_dice_throws(n, snakes, ladders);
    return 0;
}