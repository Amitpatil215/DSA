/*
Ways To Make Coin Change

venice 22

Problem Statement
You are given an infinite supply of coins of each of denominations D = {D0, D1,
D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in
which you can make a change for value V using coins of denominations from D.
Print 0, if a change isn't possible. Input Format The first line of input
contains an integer N, representing the total number of denominations.

Time Limit: 1sec
Sample Input 1 :
3
1 2 3
4
Sample Output 1:
4

Explanation For Sample Output 1:
We can make a change for the value V = 4 in four ways.
1. (1,1,1,1),
2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1)
and (1, 2, 1)]
3. (1, 3), and
4. (2, 2)

Sample Input 2 :
3
5 3 2
1
Sample Output 2:
0
 */
// Recursion
int cwtmc(int index, int value, int *denominations) {
    if (index == 0) {
        return value % denominations[index] == 0;
    }
    if (value == 0) {
        return 1;
    }
    int take = 0;
    if (value - denominations[index] >= 0) {
        take = cwtmc(index, value - denominations[index], denominations);
    }
    int doNotTake = cwtmc(index - 1, value, denominations);
    return take + doNotTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    return cwtmc(n - 1, value, denominations);
}

// recursion + memoization

#include <bits/stdc++.h>
long cwtmc(int index, int value, int *denominations, vector<vector<long>> &dp) {
    if (index == 0) {
        return value % denominations[index] == 0;
    }
    if (value == 0) {
        return 1;
    }
    if (dp[index][value] != -1) {
        return dp[index][value];
    }
    long take = 0;
    if (value - denominations[index] >= 0) {
        take = cwtmc(index, value - denominations[index], denominations, dp);
    }
    long doNotTake = cwtmc(index - 1, value, denominations, dp);
    return dp[index][value] = take + doNotTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return cwtmc(n - 1, value, denominations, dp);
}

// Tabulation
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<vector<long>> dp(n, vector<long>(value + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int val = 0; val <= value; val++) {
            if (val == 0) {
                dp[i][0] = 1;
                continue;
            }
            if (i == 0) {
                dp[0][val] = (val % denominations[0]) == 0;
            } else {
                long take = 0;
                if (val - denominations[i] >= 0) {
                    take = dp[i][val - denominations[i]];
                }
                long doNotTake = dp[i - 1][val];
                dp[i][val] = take + doNotTake;
            }
        }
    }
    return dp[n - 1][value];
}

// Tabulation + space Optimization
long countWaysToMakeChange(int *denominations, int n, int value) {
    vector<long> prev(value + 1, 0);
    vector<long> curr(value + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int val = 0; val <= value; val++) {
            if (val == 0) {
                curr[0] = 1;
                continue;
            }
            if (i == 0) {
                curr[val] = (val % denominations[0]) == 0;
            } else {
                long take = 0;
                if (val - denominations[i] >= 0) {
                    take = curr[val - denominations[i]];
                }
                long doNotTake = prev[val];
                curr[val] = take + doNotTake;
            }
        }
        prev = curr;
    }
    return prev[value];
}