/*
Unbounded Knapsack

venice 22

Problem Statement
You are given ‘N’ items with certain ‘PROFIT’ and ‘WEIGHT’ and a knapsack with
weight capacity ‘W’. You need to fill the knapsack with the items in such a way
that you get the maximum profit. You are allowed to take one item multiple
times. For Example Let us say we have 'N' = 3 items and a knapsack of capacity
'W' =  10 'PROFIT' = { 5, 11, 13 } 'WEIGHT' = { 2, 4, 6 }

We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 i.e ‘27’. Therefore maximum profit = 27.

Constraints
1 <= T <= 50
1 <= N <= 10^3
1 <= W <= 10^3
1 <= PROFIT[ i ] , WEIGHT[ i ] <= 10^8

Time Limit: 1sec
Sample Input 1
2
3 15
7 2 4
5 10 20
2 3
6 12
4 17
Sample Output 1
21
0
Explanation Of Sample Input 1
Test Case 1:  The given knapsack capacity is 15. We can fill the knapsack as [5,
5, 5] and [10, 5]. We will get a maximum profit of 21.

Test Case 2: We can clearly see that no item has wait less than knapsack
capacity. Therefore we can not fill knapsack with any item.
*/

// recursion
int uk(int index, int w, vector<int> &profit, vector<int> &weight) {
    if (w == 0) {
        return 0;
    }
    if (index == 0) {
        int noOfItemCanBePicked = w / weight[index];
        return noOfItemCanBePicked * profit[index];
    }
    int pick = 0;
    if (w - weight[index] >= 0) {
        pick = profit[index] + uk(index, w - weight[index], profit, weight);
    }
    int doNotPick = 0 + uk(index - 1, w, profit, weight);
    return max(pick, doNotPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    return uk(n - 1, w, profit, weight);
}

// recursion + memoization
int uk(int index, int w, vector<int> &profit, vector<int> &weight,
       vector<vector<int>> &dp) {
    if (w == 0) {
        return 0;
    }
    if (index == 0) {
        int noOfItemCanBePicked = w / weight[index];
        return noOfItemCanBePicked * profit[index];
    }
    if (dp[index][w] != -1) {
        return dp[index][w];
    }
    int pick = 0;
    if (w - weight[index] >= 0) {
        pick = profit[index] + uk(index, w - weight[index], profit, weight, dp);
    }
    int doNotPick = 0 + uk(index - 1, w, profit, weight, dp);
    return dp[index][w] = max(pick, doNotPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return uk(n - 1, w, profit, weight, dp);
}

// tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int index = 0; index < n; index++) {
        for (int wt = 0; wt <= w; wt++) {
            if (wt == 0) {
                dp[index][0] = 0;
            } else if (index == 0) {
                int noOfItemCanBePicked = wt / weight[index];
                dp[0][wt] = noOfItemCanBePicked * profit[index];
            } else {
                int pick = 0;
                if (wt - weight[index] >= 0) {
                    pick = profit[index] + dp[index][wt - weight[index]];
                }
                int doNotPick = 0 + dp[index - 1][wt];
                dp[index][wt] = max(pick, doNotPick);
            }
        }
    }
    return dp[n - 1][w];
}

// Tabulation + space Optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> prev(w + 1, 0);
    vector<int> curr(w + 1, 0);
    for (int index = 0; index < n; index++) {
        for (int wt = 0; wt <= w; wt++) {
            if (wt == 0) {
                curr[0] = 0;
            } else if (index == 0) {
                int noOfItemCanBePicked = wt / weight[index];
                curr[wt] = noOfItemCanBePicked * profit[index];
            } else {
                int pick = 0;
                if (wt - weight[index] >= 0) {
                    pick = profit[index] + curr[wt - weight[index]];
                }
                int doNotPick = 0 + prev[wt];
                curr[wt] = max(pick, doNotPick);
            }
        }
        prev = curr;
    }
    return prev[w];
}

// Tabulation + 1 array space optimization
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {
    vector<int> prev(w + 1, 0);
    for (int index = 0; index < n; index++) {
        for (int wt = 0; wt <= w; wt++) {
            if (wt == 0) {
                prev[0] = 0;
            } else if (index == 0) {
                int noOfItemCanBePicked = wt / weight[index];
                prev[wt] = noOfItemCanBePicked * profit[index];
            } else {
                int pick = 0;
                if (wt - weight[index] >= 0) {
                    pick = profit[index] + prev[wt - weight[index]];
                }
                int doNotPick = 0 + prev[wt];
                prev[wt] = max(pick, doNotPick);
            }
        }
    }
    return prev[w];
}
