/*
Mining Diamonds

venice 48

Problem Statement
There are ‘N’ diamonds in a mine. The size of each diamond is given in the form
of integer array ‘A’. If the miner mines a diamond, then he gets 'size of
previous unmined diamond * size of currently mined diamond * size of next
unmined diamond' number of coins. If there isn’t any next or previous unmined
diamond then their size is replaced by 1 while calculating the number of coins.
Vladimir, a dumb miner was assigned the task to mine all diamonds. Since he is
dumb he asks for your help to determine the maximum number of coins that he can
earn by mining the diamonds in an optimal order. 

For Example: Suppose ‘N’ = 3,
and ‘A’ = [7, 1, 8]

The optimal order for mining diamonds will be [2, 1, 3].
State of mine -    [7, 1, 8]    [7, 8]    [8]
Coins earned -    (7*1*8) + (1*7*8) + (1*8*1)  = 56 + 56 + 8 = 120
Hence output will be 120.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100
0 ≤ A[i] ≤ 100
1 ≤ ΣN ≤ 300

Time limit: 1 Sec
Sample Input 1 :
2
3
7 1 8
2
9 1

? Sample Output 1 :
120
18
Explanation For Sample Input 1 :
For First Case - Same as explained in above example.

For the second case -
‘N’ = 2, and ‘A’ = [9, 1]

The optimal order for mining diamonds will be [2, 1].
State of mine -    [9, 1]    [9]
Coins earned -    (1*9*1) + (1*9*1) = 9 + 9 = 18
Hence output will be 18..

? Sample Input 2 :
2
5
1 2 3 4 5
4
1 5 2 8
Sample Output 2 :
110
136
 */

//  Recursion
#include <bits/stdc++.h>
int mc(int start, int end, vector<int>& a) {
    if (start > end) {
        return 0;
    }
    int maxxi = INT_MIN;
    for (int index = start; index <= end; index++) {
        int coins = (a[start - 1] * a[index] * a[end + 1]) +
                    mc(start, index - 1, a) + mc(index + 1, end, a);
        maxxi = max(maxxi, coins);
    }
    return maxxi;
}
int maxCoins(vector<int>& a) {
    int n = a.size();

    a.push_back(1);
    a.insert(a.begin(), 1);

    return mc(1, n, a);
}

// memoization
#include <bits/stdc++.h>
int mc(int start, int end, vector<int>& a, vector<vector<int>>& dp) {
    if (start > end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    int maxxi = INT_MIN;
    for (int index = start; index <= end; index++) {
        int coins = (a[start - 1] * a[index] * a[end + 1]) +
                    mc(start, index - 1, a, dp) + mc(index + 1, end, a, dp);
        maxxi = max(maxxi, coins);
    }

    return dp[start][end] = maxxi;
}
int maxCoins(vector<int>& a) {
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return mc(1, n, a, dp);
}
// Tabulation
#include <bits/stdc++.h>
int mc(int start, int end, vector<int>& a, vector<vector<int>>& dp) {
    if (start > end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    int maxxi = INT_MIN;
    for (int index = start; index <= end; index++) {
        int coins = (a[start - 1] * a[index] * a[end + 1]) +
                    mc(start, index - 1, a, dp) + mc(index + 1, end, a, dp);
        maxxi = max(maxxi, coins);
    }

    return dp[start][end] = maxxi;
}
int maxCoins(vector<int>& a) {
    int n = a.size();
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int start = n; start >= 1; start--) {
        for (int end = 1; end <= n; end++) {
            if (start > end) {
                dp[start][end] = 0;
            }
            int maxxi = INT_MIN;
            for (int index = start; index <= end; index++) {
                int coins = (a[start - 1] * a[index] * a[end + 1]) +
                            mc(start, index - 1, a, dp) +
                            mc(index + 1, end, a, dp);
                maxxi = max(maxxi, coins);
            }

            dp[start][end] = maxxi;
        }
    }
    return dp[1][n];
}