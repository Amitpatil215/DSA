#include <bits/stdc++.h>
using namespace std;

int firstIndex(int a[], int i, int n, int k)
{
    if (n == 0)
    {
        return -1;
    }

    if (a[i] == k)
    {
        return i;
    }
    return firstIndex(a, i + 1, n - 1, k);
}

int main()
{
    int a[] = {1, 2, 3, 4, 3, 6, 3, 8};
    cout << firstIndex(a, 0, 8, 3);
    return 0;
}