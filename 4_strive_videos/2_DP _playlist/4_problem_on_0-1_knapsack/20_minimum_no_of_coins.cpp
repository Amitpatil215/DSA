/*

Minimum Coins
venice 19

Problem Statement
Bob went to his favourite bakery to buy some pastries. After picking up his
favourite pastries his total bill was P cents. Bob lives in Berland where all
the money is in the form of coins with denominations {1, 2, 5, 10, 20, 50, 100,
500, 1000}. Bob is not very good at maths and thinks fewer coins mean less money
and he will be happy if he gives minimum number of coins to the shopkeeper. Help
Bob to find the minimum number of coins that sums to P cents (assume that Bob
has an infinite number of coins of all denominations).

ple Input 1:
3
60
10
24
Sample Output 1:
2
1
3
Explanation Of Sample Input 1:
In the 1st test case, we need one coin of 50 cents and one coin of 10 cents.
In the 2nd test case, we need a coin of 10 cents.
In the 3rd test case, we need one coin of 20 cents and two coins of 2 cents.
 */

// Recursion
#include <bits/stdc++.h>
int mc(int index, int target, vector<int> &denominations) {
    if (target == 0) {
        return 0;
    }
    if (index == 0) {
        // if there is single element in the array and of we able to use it to
        // make target then return no of denominations if not then we dont know
        // how many coins would be needed
        if (target % denominations[0] == 0) {
            return target / denominations[0];
        } else {
            return 1e10;
        }
    } else {
        int take = INT_MAX;
        if (target >= denominations[index]) {
            take = 1 + mc(index, target - denominations[index], denominations);
        }
        int doNotTake = 0 + mc(index - 1, target, denominations);
        return min(take, doNotTake);
    }
}

int minimumCoins(int p) {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    return mc(denominations.size() - 1, p, denominations);
}

// Recursion + memoization
#include <bits/stdc++.h>
int mc(int index, int target, vector<int> &denominations,
       vector<vector<int>> &dp) {
    if (target == 0) {
        return 0;
    }
    if (index == 0) {
        // if there is single element in the array and of we able to use it to
        // make target then return no of denominations if not then we dont know
        // how many coins would be needed
        if (target % denominations[0] == 0) {
            return target / denominations[0];
        } else {
            return 1e10;
        }
    }
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    int take = INT_MAX;
    if (target >= denominations[index]) {
        take = 1 + mc(index, target - denominations[index], denominations, dp);
    }
    int doNotTake = 0 + mc(index - 1, target, denominations, dp);
    return dp[index][target] = min(take, doNotTake);
}

int minimumCoins(int p) {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = denominations.size();
    vector<vector<int>> dp(n, vector<int>(p + 1, -1));
    return mc(denominations.size() - 1, p, denominations, dp);
}

// Tabulation
#include <bits/stdc++.h>
int minimumCoins(int p) {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = denominations.size();

    vector<vector<int>> dp(n, vector<int>(p + 1, 1e9));

    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= p; target++) {
            if (target == 0) {
                dp[i][target] = 0;
            }
            if (i == 0) {
                if (target % denominations[0] == 0) {
                    dp[i][target] = target / denominations[0];
                }
            } else {
                int take = INT_MAX;
                if (target >= denominations[i]) {
                    take = 1 + dp[i][target - denominations[i]];
                }
                int doNotTake = 0 + dp[i - 1][target];
                dp[i][target] = min(take, doNotTake);
            }
        }
    }
    return dp[n - 1][p];
}
// Tabulation + space optimization
#include <bits/stdc++.h>
int minimumCoins(int p) {
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = denominations.size();
    vector<int> prev(p + 1, 1e9);
    for (int i = 0; i < n; i++) {
        vector<int> curr(p + 1, 1e9);
        for (int target = 0; target <= p; target++) {
            if (target == 0) {
                curr[target] = 0;
            }
            if (i == 0) {
                if (target % denominations[0] == 0) {
                    curr[target] = target / denominations[0];
                }
            } else {
                int take = INT_MAX;
                if (target >= denominations[i]) {
                    take = 1 + curr[target - denominations[i]];
                }
                int doNotTake = 0 + prev[target];
                curr[target] = min(take, doNotTake);
            }
        }
        prev = curr;
    }
    return prev[p];
}