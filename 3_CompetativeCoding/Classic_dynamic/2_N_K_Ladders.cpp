#include <bits/stdc++.h>
using namespace std;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

// recursive soln O(k^n)

int noOfWaysToReach(int n, int k)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        ways += noOfWaysToReach(n - i, k);
    }
    return ways;
}
// top down approach
int noOfWaysToReach1(int n, int k, int arr[])
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (arr[n] != 0)
    {
        return arr[n];
    }
    int ways = 0;
    for (int i = 1; i <= k; i++)
    {
        ways += noOfWaysToReach(n - i, k);
    }
    arr[n] = ways;
    return arr[n];
}

// Bottom Up Approach
int noOfWaysToReach2(int n, int k, int arr[])
{
    arr[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int jump = 1; jump <= k; jump++)
        {
            if ((i - jump) >= 0)
            {
                arr[i] += arr[i - jump];
            }
        }
    }
    return arr[n];
}
void solve()
{
    int n, k;
    cin >> n >> k;
    int arr[n + 1] = {0};
    // cout << noOfWaysToReach(n, k);
    // cout << noOfWaysToReach1(n, k, arr);
    cout << noOfWaysToReach2(n, k, arr);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Work/Interview Prep/DSA/playground/input.txt", "r", stdin);
    freopen("E:/Work/Interview Prep/DSA/playground/output.txt", "w", stdout);
#endif
    clock_t z = clock();
    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}