/*

Best Time to Buy and Sell Stock

venice 35

Problem Statement
You are given an array/list 'prices' where the elements of the array represent
the prices of the stock as they were yesterday and indices of the array
represent minutes. Your task is to find and return the maximum profit you can
make by buying and selling the stock. You can buy and sell the stock only once.

Note:
You can’t sell without buying first.

For Example:
For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its
price is Rs. 2 and selling it at minute 2 when its price is Rs. 150. So, the
output will be 148.

Constraints:
1 <= T <= 10
2 <= N <= 10^4
1 <= ARR[i] <= 10^9

Time Limit: 1 sec.

Sample Input 1:
2
4
1 2 3 4
4
2 2 2 2
Sample Output 1:
3
0

Explanation For Sample Output 1:
For the first test case, it’s optimal to buy the stock at minute 0 and sell it
at minute 3 to get a maximum profit of 3.

For the second test case, the maximum profit will be 0 for all possible ways of
buying and selling stock. 

Sample Input 2:

2
6
17 20 11 9 12 6
4
98 101 66 72

Sample Output 2:
3
6
 */

#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    int minStockPrice = prices[0];
    int maxProfit = 0;
    for (int price : prices) {
        int sellingPrice = price - minStockPrice;
        maxProfit = max(maxProfit, sellingPrice);
        minStockPrice = min(minStockPrice, price);
    }
    return maxProfit;
}