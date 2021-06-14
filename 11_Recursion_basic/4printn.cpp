#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    //base case
    if (n <= 0)
    {
        return;
    }

    // recursive case
    print(n - 1);
    cout << n << endl;
}

void printDesc(int n)
{
    //base case
    if (n <= 0)
    {
        return;
    }

    cout << n << endl;
    // recursive case
    printDesc(n - 1);
}

int main()
{
    print(5);
    printDesc(6);
    return 0;
}