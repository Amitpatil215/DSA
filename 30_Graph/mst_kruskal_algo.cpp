#include "adjacencyMatrix.cpp"

// Disjoint set Union
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N); // size of each set

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] = sz[a] + sz[b];
    }
}

void MST_Kruskal(vector<vector<int>> graph)
{
}
void print(vector<vector<int>> graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
int main() // 4 4   1 3 6  3 4 9  3 2 7  2 4 8
{
    for (int i = 0; i < N; i++)
    {
        make_set(i);
    }
    cout << "No of vertices"
         << " No of edges" << endl;
    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix;
    for (int i = 0; i < e; i++)
    {
        int v1, v2, weight;
        cout << "vertex1"
             << " vertex1 "
             << "Weight" << endl;
        cin >> v1 >> v2 >> weight;
        matrix.push_back({weight, v1, v2});
    }
    print(matrix);
    sort(matrix.begin(), matrix.end());
    cout << "sorted" << endl;
    print(matrix);

    int cost = 0;
    for (auto i : matrix)
    {
        int w = i[0];
        int v1 = i[1];
        int v2 = i[2];
        int x = find_set(v1);
        int y = find_set(v2);

        if (x == y) // lies in the same set
        {
            continue;
        }
        else
        {
            cout << v1 << " " << v2 << endl;
            cost += w;
            union_sets(v1, v2);
        }
    }
    cout << "Cost" << cost;
    return 0;
}