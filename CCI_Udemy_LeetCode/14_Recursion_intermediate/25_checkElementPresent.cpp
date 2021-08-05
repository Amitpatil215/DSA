#include <bits/stdc++.h>
using namespace std;

bool isPresent(int a[], int k, int n)
{
    if (n == 0)
    {
        return false;
    }
    if (a[0] == k)
    {
        return true;
    }
    else
    {
        return isPresent(a + 1, k, n - 1);
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << isPresent(a, 4, 9) << endl;
    cout << isPresent(a, 10, 9) << endl;
    return 0;
}