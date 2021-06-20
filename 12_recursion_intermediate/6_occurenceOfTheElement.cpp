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

int occurenceOfTheElement2(int a[], int n, int x, int i)
{

    //base case
    if (i == n)
    {
        return 0;
    }

    int howManyTimesPresent = occurenceOfTheElement2(a, n, x, i + 1);

    if (a[i] == x)
    {
        howManyTimesPresent = howManyTimesPresent + 1;
    }
    return howManyTimesPresent;
}

int main()
{
    int a[] = {1, 3, 2, 2, 5, 3, 4, 2};
    int ans = 0;
    cout << occurenceOfTheElement2(a, 8, 2, 0);
}