#include <bits/stdc++.h>
using namespace std;

int occurence(int a[], int i, int k)
{
    if (i == -1)
    {
        return 0;
    }
    if (a[i] == k)
    {
        return 1 + occurence(a, i - 1, k);
    }
    return occurence(a, i - 1, k);
}
int main()
{
    int a[] = {1, 2, 3, 4, 3, 5, 6, 3, 3};
    cout << occurence(a, 8, 3);
    return 0;
}