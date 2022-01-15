#include <bits/stdc++.h>
using namespace std;

void storeAllPosition(int a[], int n, int x, int i, vector<int> &ans)
{
    if (i == n)
    {
        return;
    }

    if (a[i] == x)
    {
        ans.push_back(i);
    }

    storeAllPosition(a, n, x, i + 1, ans);
}

int storeAllPositionInArray(int a[], int n, int x, int i, int posArr[], int pos)
{
    if (i == n)
    {
        return pos;
    }

    if (a[i] == x)
    {
        posArr[pos] = i;
        pos++;
    }

    storeAllPositionInArray(a, n, x, i + 1, posArr, pos);
}
int main()
{
    int a[] = {1, 4, 3, 4, 4};
    vector<int> v;
    storeAllPosition(a, 5, 4, 0, v);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
    int out[10];
    int lengthOfArray = storeAllPositionInArray(a, 5, 4, 0, out, 0);

    for (int i = 0; i < lengthOfArray; i++)
    {
        cout << out[i] << " ";
    }
    return 0;
}