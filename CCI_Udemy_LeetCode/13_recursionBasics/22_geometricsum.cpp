#include <bits/stdc++.h>
using namespace std;

double gsum(int n)
{
    if (n == 0)
    {
        return 1.0;
    }

    return 1.0 / pow(2, n) + gsum(n - 1);
}

int main()
{
    cout << gsum(2);

    return 0;
}