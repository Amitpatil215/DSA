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

void BFSPrint(vector<vector<int>> matrix, int sv)
{
    int n = matrix.size();

    queue<int> q;
    vector<bool> visited(n, 0);
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
    vector<bool> visited(n, 0);
    //DFSPrint(matrix, 0, visited);
    BFSPrint(matrix, 0);
    return 0;
}