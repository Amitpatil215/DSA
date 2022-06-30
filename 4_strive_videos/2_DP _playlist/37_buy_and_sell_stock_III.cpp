/*
123. Best Time to Buy and Sell Stock III

venice 36 

You are given an array prices where prices[i] is the price of a given stock on
the ith day.
Find the maximum profit you can achieve. You may complete at most two
transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3. Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit =
4-1 = 3. Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4. Note that you cannot buy on day 1, buy on day 2 and sell them later, as
you are engaging multiple transactions at the same time. You must sell before
buying again. Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.


Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

 */
// Recursion
class Solution {
   public:
    int mp(int index, bool isEarlierBought, int cap, vector<int>& prices,
           int n) {
        if (index == n) {
            return 0;
        }

        if (cap == 0) {
            return 0;
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell =
                prices[index] + mp(index + 1, false, cap - 1, prices, n);
            int willNotSell = 0 + mp(index + 1, true, cap, prices, n);
            return max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy = -prices[index] + mp(index + 1, true, cap, prices, n);
            int willNotBuy = 0 + mp(index + 1, false, cap, prices, n);
            return max(willBuy, willNotBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        return mp(0, false, 2, prices, prices.size());
    }
};

// Recursion + memoization
//  Recursion + Memoization
class Solution {
   public:
    int mp(int index, bool isEarlierBought, int cap, vector<int>& prices, int n,
           vector<vector<vector<int>>>& dp) {
        if (index == n) {
            return 0;
        }

        if (cap == 0) {
            return 0;
        }

        if (dp[index][isEarlierBought][cap] != -1) {
            return dp[index][isEarlierBought][cap];
        }

        if (isEarlierBought) {
            // we can only sell
            int willSell =
                prices[index] + mp(index + 1, false, cap - 1, prices, n, dp);
            int willNotSell = 0 + mp(index + 1, true, cap, prices, n, dp);
            return dp[index][isEarlierBought][cap] = max(willSell, willNotSell);
        } else {
            // we can only buy
            int willBuy =
                -prices[index] + mp(index + 1, true, cap, prices, n, dp);
            int willNotBuy = 0 + mp(index + 1, false, cap, prices, n, dp);
            return dp[index][isEarlierBought][cap] = max(willBuy, willNotBuy);
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return mp(0, false, 2, prices, n, dp);
    }
};

// Tabulation
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                for (int cap = 0; cap <= 2; cap++) {
                    if (index == n) {  // base case
                        dp[index][isEarlierBought][cap] = 0;
                    } else if (cap == 0) {
                        dp[index][isEarlierBought][cap] = 0;
                    } else {
                        if (isEarlierBought) {
                            // we can only sell
                            int willSell =
                                prices[index] + dp[index + 1][false][cap - 1];
                            int willNotSell = 0 + dp[index + 1][true][cap];
                            dp[index][isEarlierBought][cap] =
                                max(willSell, willNotSell);
                        } else {
                            // we can only buy
                            int willBuy =
                                -prices[index] + dp[index + 1][true][cap];
                            int willNotBuy = 0 + dp[index + 1][false][cap];
                            dp[index][isEarlierBought][cap] =
                                max(willBuy, willNotBuy);
                        }
                    }
                }
            }
        }
        return dp[0][false][2];
    }
};

// Tabulation + space optimization
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                for (int cap = 0; cap <= 2; cap++) {
                    if (index == n) {  // base case
                        prev[isEarlierBought][cap] = 0;
                    } else if (cap == 0) {
                        curr[isEarlierBought][cap] = 0;
                    } else {
                        if (isEarlierBought) {
                            // we can only sell
                            int willSell = prices[index] + prev[false][cap - 1];
                            int willNotSell = 0 + prev[true][cap];
                            curr[isEarlierBought][cap] =
                                max(willSell, willNotSell);
                        } else {
                            // we can only buy
                            int willBuy = -prices[index] + prev[true][cap];
                            int willNotBuy = 0 + prev[false][cap];
                            curr[isEarlierBought][cap] =
                                max(willBuy, willNotBuy);
                        }
                    }
                }
            }
            prev = curr;
        }
        return prev[false][2];
    }
};