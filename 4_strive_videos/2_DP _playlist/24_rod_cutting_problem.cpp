/*
Rod cutting problem

venice 24

Problem Statement
Given a rod of length ‘N’ units. The rod can be cut into different sizes and
each size has a cost associated with it. Determine the maximum cost obtained by
cutting the rod and selling its pieces. Note:
1. The sizes will range from 1 to ‘N’ and will be integers.

2. The sum of the pieces cut should be equal to ‘N’.

3. Consider 1-based indexing.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= A[i] <= 100

Where ‘T’ is the total number of test cases, ‘N’ denotes the length of the rod,
and A[i] is the cost of sub-length.

Time limit: 1 sec.

Sample Input 1:
2
5
2 5 7 8 10
8
3 5 8 9 10 17 17 20
Sample Output 1:
12
24

Explanation Of Sample Input 1:
Test case 1:

All possible partitions are:
1,1,1,1,1           max_cost=(2+2+2+2+2)=10
1,1,1,2             max_cost=(2+2+2+5)=11
1,1,3               max_cost=(2+2+7)=11
1,4                 max_cost=(2+8)=10
5                   max_cost=(10)=10
2,3                 max_cost=(5+7)=12
1,2,2               max _cost=(1+5+5)=12

Clearly, if we cut the rod into lengths 1,2,2, or 2,3, we get the maximum cost
which is 12.


Test case 2:

Possible partitions are:
1,1,1,1,1,1,1,1         max_cost=(3+3+3+3+3+3+3+3)=24
1,1,1,1,1,1,2           max_cost=(3+3+3+3+3+3+5)=23
1,1,1,1,2,2             max_cost=(3+3+3+3+5+5)=22
and so on….

If we cut the rod into 8 pieces of length 1, for each piece 3 adds up to the
cost. Hence for 8 pieces, we get 8*3 = 24.
 */

// Recursion
int cr(int index, int targetLength, vector<int> &price) {
    if (targetLength == 0) {
        return 0;
    }
    if (index == 0) {
        // at 0th index we will have 1 length rod
        int possibleCuts = targetLength / 1;
        return possibleCuts * price[0];
    }
    int pick = 0;
    if ((targetLength - (index + 1)) >= 0) {
        pick = price[index] + cr(index, targetLength - (index + 1), price);
    }
    int doNotPick = 0 + cr(index - 1, targetLength, price);
    return max(pick, doNotPick);
}
int cutRod(vector<int> &price, int n) { return cr(n - 1, n, price); }

// recursion + memoization
int cr(int index, int targetLength, vector<int> &price,
       vector<vector<int>> &dp) {
    if (targetLength == 0) {
        return 0;
    }
    if (index == 0) {
        // at 0th index we will have 1 length rod
        int possibleCuts = targetLength / 1;
        return possibleCuts * price[0];
    }
    if (dp[index][targetLength] != -1) {
        return dp[index][targetLength];
    }
    int pick = 0;
    if ((targetLength - (index + 1)) >= 0) {
        pick = price[index] + cr(index, targetLength - (index + 1), price, dp);
    }
    int doNotPick = 0 + cr(index - 1, targetLength, price, dp);
    return dp[index][targetLength] = max(pick, doNotPick);
}
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return cr(n - 1, n, price, dp);
}

// Tabulation
int cutRod(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int index = 0; index < n; index++) {
        for (int targetLength = 0; targetLength <= n; targetLength++) {
            if (targetLength == 0) {
                dp[index][0] = 0;
            } else if (index == 0) {
                // at 0th index we will have 1 length rod
                int possibleCuts = targetLength / 1;
                dp[index][targetLength] = possibleCuts * price[0];
            } else {
                int pick = 0;
                if ((targetLength - (index + 1)) >= 0) {
                    pick = price[index] + dp[index][targetLength - (index + 1)];
                }
                int doNotPick = 0 + dp[index - 1][targetLength];
                dp[index][targetLength] = max(pick, doNotPick);
            }
        }
    }
    return dp[n - 1][n];
}
// Tabulation + Space optimization
int cutRod(vector<int> &price, int n) {
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int index = 0; index < n; index++) {
        for (int targetLength = 0; targetLength <= n; targetLength++) {
            if (targetLength == 0) {
                curr[0] = 0;
            } else if (index == 0) {
                // at 0th index we will have 1 length rod
                int possibleCuts = targetLength / 1;
                curr[targetLength] = possibleCuts * price[0];
            } else {
                int pick = 0;
                if ((targetLength - (index + 1)) >= 0) {
                    pick = price[index] + curr[targetLength - (index + 1)];
                }
                int doNotPick = 0 + prev[targetLength];
                curr[targetLength] = max(pick, doNotPick);
            }
        }
        prev = curr;
    }
    return prev[n];
}