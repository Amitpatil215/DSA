/*
188. Best Time to Buy and Sell Stock IV

You are given an integer array prices where prices[i] is the price of a given
stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k
transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
4-2 = 2. Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit =
3-0 = 3.


Constraints:
0 <= k <= 100
0 <= prices.length <= 1000
0 <= prices[i] <= 1000

 */

// Tabulation + space optimization
class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for (int index = n; index >= 0; index--) {
            for (int isEarlierBought = 0; isEarlierBought < 2;
                 isEarlierBought++) {
                for (int cap = 0; cap <= k; cap++) {
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
        return prev[false][k];
    }
};