#include <bits/stdc++.h>
using namespace std;

void printAllPosition(int a[], int n, int x, int i)
{
    if (i == n)
    {
        return;
    }

    if (a[i] == x)
    {
        cout << i << endl;
    }

    printAllPosition(a, n, x, i + 1);
}

int main()
{
    int a[] = {1, 4, 3, 4, 4};
    printAllPosition(a, 5, 4, 0);
    return 0;
}