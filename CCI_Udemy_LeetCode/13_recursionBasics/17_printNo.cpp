#include <bits/stdc++.h>
using namespace std;

void printNo(int n)
{

    if (n == 0)
    {
        return;
    }
    printNo(n - 1);
    cout << n << endl;
    return;
}

int main()
{
    printNo(5);
    return 0;
}