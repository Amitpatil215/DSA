#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    // recursive case
    int smallOutput1 = fib(n - 1);
    int smallOutput2 = fib(n - 2);

    // calculation
    return smallOutput1 + smallOutput2;
}

int main()
{
    int n;
    cin >> n;
    int ans = fib(n);
    cout << ans << endl;
    return 0;
}