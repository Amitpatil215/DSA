#include <bits/stdc++.h>
using namespace std;

void DFSPrint(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    cout << sv << endl;
    visited[sv] = true;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            DFSPrint(v, i, visited);
        }
    }
}

void DFS(vector<vector<int>> v)
{
    int n = v.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFSPrint(v, i, visited);
        }
    }
}

void BFSPrint(vector<vector<int>> matrix, int sv, vector<bool> &visited)
{
    int n = matrix.size();

    queue<int> q;

    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << endl;

        for (int i = 0; i < n; i++)
        {
            if (matrix[currentVertex][i] == 1 && visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
void BFS(vector<vector<int>> v)
{
    int n = v.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFSPrint(v, i, visited);
        }
    }
}
/*
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int fv, sv;
        cout << "First Vertex" << endl;
        cin >> fv;
        cout << "Second Vertex" << endl;
        cin >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    // DFS(matrix);
    // BFS(matrix);
    return 0;
}
 */