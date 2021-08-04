#include <bits/stdc++.h>
using namespace std;

int fab(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }

    return fab(n - 1) + fab(n - 2);
}

int main()
{
    cout << fab(7) << endl;
    return 0;
}