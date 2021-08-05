#include <bits/stdc++.h>
using namespace std;

int lastIndex(int a[], int i, int k)
{
    if (i == -1)
    {
        return -1;
    }

    if (a[i] == k)
    {
        return i;
    }
    return lastIndex(a, i - 1, k);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 3, 6, 7};
    cout << lastIndex(a, 7, 3);

    return 0;
}