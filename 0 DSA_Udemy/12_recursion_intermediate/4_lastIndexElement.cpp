#include <bits/stdc++.h>
using namespace std;

int lastIndexOftheElement(int a[], int n, int x, int i)
{
    //base case
    if (i == -1)
    {
        return -1;
    }

    if (a[i] == x)
    {
        return i;
    }

    int indexFoundInSmallPart = lastIndexOftheElement(a, n, x, i - 1);

    return indexFoundInSmallPart;
}

int main()
{
    int a[] = {1, 4, 3, 4, 4};
    cout<<lastIndexOftheElement(a, 5, 3, 4);
    return 0;
}