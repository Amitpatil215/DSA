#include <bits/stdc++.h>
using namespace std;

void makeset(int N, int parent[])
{
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
}

int find(int i, int parent[])
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

bool comp(vector<int> A, vector<int> B)
{
    return A[2] < B[2];
}

int cost(int N, vector<vector<int>> &edges)
{

    sort(edges.begin(), edges.end(), comp);
    int parent[N + 1];
    makeset(N, parent);
    int cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int s = edges[i][0];
        int d = edges[i][1];
        cout << s << " " << d << endl;
        int rs = find(s, parent);
        int rd = find(d, parent);
        if (rs != rd)
        {
            // no cycle
            cost += edges[i][2];
            parent[rs] = rd; // union
        }
    }
    return cost;
}

int main()
{
    int n, edges;
    cin >> n >> edges;
    vector<vector<int>> g(edges);
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({u, v, w});
    }
    cout << cost(n, g);
    return 0;
}