#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int i, int n)
{
    if (i == n - 1)
    {
        return true;
    }
    if (a[i] < a[i + 1])
    {
        return isSorted(a, i + 1, n);
    }
    else
    {
        return false;
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    cout << isSorted(a, 0, 7);
    return 0;
}