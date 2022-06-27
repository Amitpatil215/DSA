/*
0-1 Knapsack

venice 18

A thief is robbing a store and can carry a maximal weight of W into his
knapsack. There are N items and the ith item weighs wi and is of value vi.
Considering the constraints of the maximum weight that a knapsack can carry, you
have to find and return the maximum value that a thief can generate by stealing
items.

Sample Input: 
1
4
1 2 4 5
5 4 8 6
5
Sample Output:
13

Constraints:
1 <= T <= 10
1 <= N <= 10^2
1<= wi <= 50
1 <= vi <= 10^2
1 <= W <= 10^3



Time Limit: 1 second
 */

// Recursion
int knap(int index, int maxWeight, vector<int> weight, vector<int> value) {
    // if we are left with only one element
    if (index == 0) {
        // and we have enough weight remaining then steal it
        if (weight[index] <= maxWeight) {
            return value[index];
        } else {
            return 0;
        }
    }
    int rob = 0;
    if (index > 0 && maxWeight >= weight[index]) {
        rob = value[index] +
              knap(index - 1, maxWeight - weight[index], weight, value);
    }
    int doNotRob = 0;
    if (index > 0) {
        doNotRob = 0 + knap(index - 1, maxWeight, weight, value);
    }
    return max(rob, doNotRob);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return knap(n - 1, maxWeight, weight, value);
}

// Recursion + memoization
int knap(int index, int maxWeight, vector<int> weight, vector<int> value,
         vector<vector<int>>& dp) {
    // if we are left with only one element
    if (index == 0) {
        // and we have enough weight remaining then steal it
        if (weight[index] <= maxWeight) {
            return value[index];
        } else {
            return 0;
        }
    }
    if (dp[index][maxWeight] != -1) {
        return dp[index][maxWeight];
    }
    int rob = 0;
    if (index > 0 && maxWeight >= weight[index]) {
        rob = value[index] +
              knap(index - 1, maxWeight - weight[index], weight, value, dp);
    }
    int doNotRob = 0;
    if (index > 0) {
        doNotRob = 0 + knap(index - 1, maxWeight, weight, value, dp);
    }
    return dp[index][maxWeight] = max(rob, doNotRob);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return knap(n - 1, maxWeight, weight, value, dp);
}

// Tabulation

#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int index = 0; index < n; index++) {
        for (int w = 0; w <= maxWeight; w++) {
            if (index == 0) {
                if (weight[index] <= w) {
                    dp[0][w] = value[0];
                } else {
                    dp[0][w] = 0;
                }
            } else {
                int rob = 0;
                if (index > 0 && w >= weight[index]) {
                    rob = value[index] + dp[index - 1][w - weight[index]];
                }
                int doNotRob = 0;
                if (index > 0) {
                    doNotRob = 0 + dp[index - 1][w];
                }

                dp[index][w] = max(rob, doNotRob);
            }
        }
    }
    return dp[n - 1][maxWeight];
}

// Tabulation + Space Optimization
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);
    for (int index = 0; index < n; index++) {
        vector<int> curr(maxWeight + 1, 0);
        for (int w = 0; w <= maxWeight; w++) {
            if (index == 0) {
                if (weight[index] <= w) {
                    curr[w] = value[0];
                } else {
                    curr[w] = 0;
                }
            } else {
                int rob = 0;
                if (index > 0 && w >= weight[index]) {
                    rob = value[index] + prev[w - weight[index]];
                }
                int doNotRob = 0;
                if (index > 0) {
                    doNotRob = 0 + prev[w];
                }
                curr[w] = max(rob, doNotRob);
            }
        }
        prev = curr;
    }
    return prev[maxWeight];
}

// Tabulation + single array optimization
#include <bits/stdc++.h>
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    vector<int> prev(maxWeight + 1, 0);
    for (int index = 0; index < n; index++) {
        for (int w = maxWeight; w >= 0; w--) {  // right to left
            if (index == 0) {
                if (weight[index] <= w) {
                    prev[w] = value[0];
                } else {
                    prev[w] = 0;
                }
            } else {
                int rob = 0;
                if (index > 0 && w >= weight[index]) {
                    rob = value[index] + prev[w - weight[index]];
                }
                int doNotRob = 0;
                if (index > 0) {
                    doNotRob = 0 + prev[w];
                }
                prev[w] = max(rob, doNotRob);  // updating in prev array itself
            }
        }
    }
    return prev[maxWeight];
}