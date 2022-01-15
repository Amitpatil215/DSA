#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return 1 + count(n / 10);
}

int main()
{
    cout << count(4356);

    return 0;
}