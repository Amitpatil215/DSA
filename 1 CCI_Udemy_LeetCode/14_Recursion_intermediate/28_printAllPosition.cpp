#include <bits/stdc++.h>
using namespace std;

void print(int a[], int i, int k)
{
    if (i == -1)
    {
        return;
    }
    if (a[i] == k)
    {
        cout << i << endl;
    }
    return print(a, i - 1, k);
}
int main()
{
    int a[] = {1, 2, 3, 4, 3, 5, 6, 3, 3};
    print(a, 8, 3);
    return 0;
}