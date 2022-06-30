/*
309. Best Time to Buy and Sell Stock with Cooldown

You are given an array prices where prices[i] is the price of a given stock on
the ith day.
Find the maximum profit you can achieve. You may complete as many transactions
as you like (i.e., buy one and sell one share of the stock multiple times) with
the following restrictions:
After you sell your stock, you cannot buy stock on the next day (i.e., cooldown
one day). Note: You may not engage in multiple transactions simultaneously
(i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

 */

// Recursion
class Solution {
   public:
    int mp(int index, bool isEarlierBought, vector<int>& prices, int n) {
        if (index >= n) {
            return 0;
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell = prices[index] + mp(index + 2, false, prices, n);
            int willNotSell = 0 + mp(index + 1, true, prices, n);
            return max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy = -prices[index] + mp(index + 1, true, prices, n);
            int willNotBuy = 0 + mp(index + 1, false, prices, n);
            return max(willBuy, willNotBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        return mp(0, false, prices, prices.size());
    }
};

//  Recursion + Memoization
class Solution {
   public:
    int mp(int index, bool isEarlierBought, vector<int>& prices, int n,
           vector<vector<int>>& dp) {
        if (index >= n) {
            return 0;
        }

        if (dp[index][isEarlierBought] != -1) {
            return dp[index][isEarlierBought];
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell = prices[index] + mp(index + 2, false, prices, n, dp);
            int willNotSell = 0 + mp(index + 1, true, prices, n, dp);
            return dp[index][isEarlierBought] = max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy = -prices[index] + mp(index + 1, true, prices, n, dp);
            int willNotBuy = 0 + mp(index + 1, false, prices, n, dp);
            return dp[index][isEarlierBought] = max(willBuy, willNotBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return mp(0, false, prices, n, dp);
    }
};

// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index >= n) {  // base case
                    dp[index][isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + dp[index + 2][false];
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

// Tabulation + Space optimization
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> prev2(2, 0);
        vector<int> prev1(2, 0);
        vector<int> curr(2, 0);

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {  // base case
                    prev1[isEarlierBought] = 0;
                    prev2[isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + prev2[false];
                        int willNotSell = 0 + prev1[true];
                        curr[isEarlierBought] = max(willSell, willNotSell);
                    } else {
                        // we can only buy
                        int willBuy = -prices[index] + prev1[true];
                        int willNotBuy = 0 + prev1[false];
                        curr[isEarlierBought] = max(willBuy, willNotBuy);
                    }
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[false];
    }
};