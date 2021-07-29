#include <bits/stdc++.h>
using namespace std;

// Brute Force Approch
int minSteps(int n) //T=O(2^n)
{
    //base case
    if (n <= 1)
    {
        return 0;
    }
    // recursive
    int x = minSteps(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = minSteps(n / 2);
    if (n % 3 == 0)
        z = minSteps(n / 3);

    // output
    int ans = min(x, min(y, z)) + 1;
    return ans;
}

int helper(int n, int *arr)
{
    if (n <= 1)
    {
        return 0;
    }
    // if we alredy calculated then return it
    if (arr[n] != -1)
    {
        return arr[n];
    }
    // recursive
    int x = helper(n - 1, arr);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = helper(n / 2, arr);
    if (n % 3 == 0)
        z = helper(n / 3, arr);

    // output
    int ans = min(x, min(y, z)) + 1;
    // saving for future use
    arr[n] = ans;
    return ans;
}

// Save repeated solutions in an array and reuse
// Top down DP approch or memorization approch // T=O(N)
int minSteps2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = -1;
    }
    int ans = helper(n, arr);
    delete[] arr;
    return ans;
}
// Bottom up DP or iterative solution // T=S=O(n)
int minSteps3(int n)
{
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    // dp[i] denotes min steps needed to move from i to 1 i.e. i->1
    // dp[n] denotes min steps needed to move from n to 1 i.e. n->1
    for (int i = 2; i <= n; i++)
    {
        int x = dp[i - 1];
        int y = INT_MAX, z = INT_MAX;
        if (i % 2 == 0)
            y = dp[i / 2];
        if (i % 3 == 0)
            z = dp[i / 3];
        dp[i] = min(x, min(y, z)) + 1;
    }
    int ans = dp[n];
    delete[] dp;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    cout << minSteps(n) << endl;
    cout << minSteps2(n) << endl;
    cout << minSteps3(n) << endl;
    return 0;
}