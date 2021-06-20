#include <bits/stdc++.h>
using namespace std;

void occurenceOfTheElement(int a[], int n, int x, int i, int &ans)
{
    int count = 0;
    //base case
    if (i == n)
    {
        return;
    }

    if (a[i] == x)
    {
        ans++;
    }

    occurenceOfTheElement(a, n, x, i + 1, ans);
}

int main()
{
    int a[] = {1, 3, 2, 2, 5, 3, 4, 2};
    int ans = 0;
    occurenceOfTheElement(a, 8, 2, 0, ans);
    cout << ans << endl;
}