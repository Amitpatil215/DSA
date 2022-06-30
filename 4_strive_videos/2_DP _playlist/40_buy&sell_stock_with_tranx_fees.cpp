/*
714. Best Time to Buy and Sell Stock with Transaction Fee

You are given an array prices where prices[i] is the price of a given stock on
the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions
as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8

Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6


Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
 */

// Recursion
class Solution {
   public:
    int mp(int index, int isEarlierBought, vector<int>& prices, int fee,
           int n) {
        if (index == n) {
            return 0;
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell =
                prices[index] - fee + mp(index + 1, false, prices, fee, n);
            int willNotSell = 0 + mp(index + 1, true, prices, fee, n);
            return max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy = -prices[index] + mp(index + 1, true, prices, fee, n);
            int willNotBuy = 0 + mp(index + 1, false, prices, fee, n);
            return max(willBuy, willNotBuy);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return mp(0, false, prices, fee, n);
    }
};

// recursion + memoization
class Solution {
   public:
    int mp(int index, int isEarlierBought, vector<int>& prices, int fee, int n,
           vector<vector<int>>& dp) {
        if (index == n) {
            return 0;
        }
        if (dp[index][isEarlierBought] != -1) {
            return dp[index][isEarlierBought];
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell =
                prices[index] - fee + mp(index + 1, false, prices, fee, n, dp);
            int willNotSell = 0 + mp(index + 1, true, prices, fee, n, dp);
            return dp[index][isEarlierBought] = max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy =
                -prices[index] + mp(index + 1, true, prices, fee, n, dp);
            int willNotBuy = 0 + mp(index + 1, false, prices, fee, n, dp);
            return dp[index][isEarlierBought] = max(willBuy, willNotBuy);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return mp(0, false, prices, fee, n, dp);
    }
};

// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {
                    dp[index][isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell =
                            prices[index] - fee + dp[index + 1][false];
                        int willNotSell = 0 + dp[index + 1][true];
                        dp[index][isEarlierBought] = max(willSell, willNotSell);
                    } else {
                        // we can only buy
                        int willBuy = -prices[index] + dp[index + 1][true];
                        int willNotBuy = 0 + dp[index + 1][false];
                        dp[index][isEarlierBought] = max(willBuy, willNotBuy);
                    }
                }
            }
        }
        return dp[0][false];
    }
};

// Tabulation + SpaceOptimization
class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        vector<int> prev(2, false);
        vector<int> curr(2, false);
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {
                    prev[isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] - fee + prev[false];
                        int willNotSell = 0 + prev[true];
                        curr[isEarlierBought] = max(willSell, willNotSell);
                    } else {
                        // we can only buy
                        int willBuy = -prices[index] + prev[true];
                        int willNotBuy = 0 + prev[false];
                        curr[isEarlierBought] = max(willBuy, willNotBuy);
                    }
                }
            }
            prev = curr;
        }
        return prev[false];
    }
};