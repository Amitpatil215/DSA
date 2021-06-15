#include <bits/stdc++.h>
using namespace std;

// check first is zeroth and 1st element is > or not then call recursion
bool isSorted(int a[], int n)
{
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (a[0] > a[1])
    {
        return false;
    }
    bool isSmallerSorted = isSorted(a + 1, n - 1);

    return isSmallerSorted;
}
// call recursion first and then check is zeroth and 1st element is > or not
bool isSorted2(int a[], int n)
{

    if (n == 0 || n == 1)
    {
        return true;
    }
    bool isSmallerSorted = isSorted(a + 1, n - 1);
    if (!isSmallerSorted)
        return false;

    return a[0] > a[1] ? false : true;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << isSorted2(a, 5);
    return 0;
}