#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n % 10 == 0 ? 1 + count(n / 10) : count(n / 10);
}
int main()
{
    cout << count(302010200);
    return 0;
}