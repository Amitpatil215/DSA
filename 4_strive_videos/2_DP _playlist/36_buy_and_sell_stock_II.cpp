/*
122. Best Time to Buy and Sell Stock II

venice 35

You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4. Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit =
6-3 = 3. Total profit is 4 + 3 = 7. Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4. Total profit is 4. Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the
stock to achieve the maximum profit of 0.


Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
 */

// Recursion
class Solution {
   public:
    int mp(int index, bool isEarlierBought, vector<int>& prices, int n) {
        if (index == n) {
            return 0;
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell = prices[index] + mp(index + 1, false, prices, n);
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
        if (index == n) {
            return 0;
        }

        if (dp[index][isEarlierBought] != -1) {
            return dp[index][isEarlierBought];
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell = prices[index] + mp(index + 1, false, prices, n, dp);
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
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {  // base case
                    dp[index][isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + dp[index + 1][false];
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

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                if (index == n) {  // base case
                    prev[isEarlierBought] = 0;
                } else {
                    if (isEarlierBought) {
                        // we can only sell
                        int willSell = prices[index] + prev[false];
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