#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int fv, sv;
        cout << "First Vertex" << endl;
        cin >> fv;
        cout << "Second Vertex" << endl;
        cin >> sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }
    return 0;
}