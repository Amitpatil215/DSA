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

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    if (isPresent(a, 5, 10))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}