#include <bits/stdc++.h>
using namespace std;

int sumOfArray(int a[], int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }

    // recursive
    int smallSumOutput = sumOfArray(a + 1, n - 1);

    return smallSumOutput + a[0];
}

int sumOfArray2(int a[], int n)
{
    //base case
    if (n == 0)
    {
        return 0;
    }

    // recursive
    int smallSumOutput = sumOfArray2(a, n - 1);

    return smallSumOutput + a[n - 1];
}

int sumOfArray3(int a[], int n, int index)
{
    //base case
    if (index == n)
    {
        return 0;
    }

    // recursive
    int smallSumOutput = sumOfArray3(a, n, index + 1);

    return smallSumOutput + a[index];
}

int main()
{
    int a[] = {1, 2, 3};

    cout << sumOfArray(a, 3) << endl;
    cout << sumOfArray2(a, 3) << endl;
    cout << sumOfArray3(a, 3, 0) << endl;
    return 0;
}