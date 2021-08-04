#include <bits/stdc++.h>
using namespace std;

int multiply(int n, int m)
{
    if (m == 0)
    {
        return 0;
    }
    return n + multiply(n, m - 1);
}
int main()
{

    cout << multiply(5, 4);
    return 0;
}