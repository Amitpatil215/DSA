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

bool isSorted3(int a[], int n)
{

    if (a[n - 2] > a[n - 1])
    {
        return false;
    }
    bool isSmallerSorted = isSorted(a, n - 1);

    return isSmallerSorted;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 3, 10, 4, 5};
    cout << isSorted3(a, 5) << endl;
    cout << isSorted3(b, 5) << endl;
    return 0;
}