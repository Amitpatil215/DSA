#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        // terminate recursion on reahcing 0
        // factorial of 0 is 1
        return 1;
    int smallAns = fact(n - 1);
    int factorial = n * smallAns;
    return factorial;
}

int main()
{
    int n;
    cin >> n;
    int ans = fact(n);
    cout << ans << endl;
    return 0;
}