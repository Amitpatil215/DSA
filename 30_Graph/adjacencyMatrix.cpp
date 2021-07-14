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
    DFSPrint(matrix, 0, visited);
    return 0;
}