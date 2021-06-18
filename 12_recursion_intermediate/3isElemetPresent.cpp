#include <bits/stdc++.h>
using namespace std;

bool isPresent(int a[], int n, int x)
{
    //base case
    if (n == 0)
    {
        return false;
    }

    if (a[0] == x)
    {
        return true;
    }

    bool isFoundInSmallArray = isPresent(a + 1, n - 1, x);

    //calculation
    return isFoundInSmallArray;
}

bool isPresent2(int a[], int n, int x, int i)
{
    //base case
    if (i == n - 1)
    {
        return false;
    }

    if (a[i] == x)
    {
        return true;
    }

    bool isFoundInSmallArray = isPresent2(a, n, x, i + 1);

    //calculation
    return isFoundInSmallArray;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    if (isPresent2(a, 5, 13, 0))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}