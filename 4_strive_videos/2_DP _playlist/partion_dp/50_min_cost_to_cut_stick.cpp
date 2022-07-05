/*
Cost to Cut a Chocolate


Problem Statement
You are given chocolate of ‘N’ length. The chocolate is labeled from 0 to ‘N’.
You are also given an array ‘CUTS’ of size ‘C’, denoting the positions at which
you can do a cut. The order of cuts can be changed. The cost of one cut is the
length of the chocolate to be cut. Therefore, the total cost is the sum of all
the cuts. Print the minimum cost to cut the chocolate. Note: All the integers in
the ‘CUTS’ array are distinct. 

For Example: Let ‘N’ be: 4 Let the ‘CUTS’ array
be: [1, 3].

Let the order of doing the cut be [1, 3].
The first cut of 1 on length 4 results in a cost of 4, and chocolate is split
into two parts of the length of 1 and 3. The second cut of 3 on length 3 results
in a cost of 3, and chocolate is split into two parts again of the length of 2
and 1. So the total cost is 7.

The cost will remain the same if we change the order of cutting. So the result
is 7.

Constraints :
1 <= T <= 10
2 <= N <= 10^5
1 <= C <= 10^3
1 <= CUTS[i] <= N - 1

Time Limit: 1 sec
Sample Input 1 :
2
4 2
1 3
5 3
1 3 4
Sample Output 1 :
7
10
Explanation For Sample Output 1 :
For test case 1:
Let the order of doing the cut be [1, 3].
The first cut of 1 on length 4 results in a cost of 4, and chocolate is split
into two parts of the length of 1 and 3. The second cut of 3 on length 3 results
in a cost of 3, and chocolate is split into two parts again of the length of 2
and 1. So the total cost is 7.

The cost will remain the same if we change the order of cutting. So the result
is 7.

For test case 2:
Let the order of doing the cut be [1, 3, 4].
The first cut of 1 on length 5 results in a cost of 5, and chocolate is split
into two parts of the length of 1 and 4. The second cut of 3 on length 4 results
in a cost of 4, and chocolate is split into two parts again of the length of 2
and 2. The total cost is 9. The third cut of 4 on length 2 results in a cost of
2, and chocolate is split into two parts again of the length of 1 and 1. The
total cost is 11.

The minimum cost will be 10 when the order of doing cuts will be: [3, 1, 4].
Sample Input 2 :
2
10 4
1 3 4 7
10 2
1 3
Sample Output 2 :
23
13
 */

#include <bits/stdc++.h>
int minCost(int start, int end, vector<int> &cuts) {
    if (start > end) {
        return 0;
    }
    int minimum = INT_MAX;
    for (int i = start; i <= end; i++) {
        int c = (cuts[end + 1] - cuts[start - 1]) +
                minCost(start, i - 1, cuts) + minCost(i + 1, end, cuts);
        minimum = min(minimum, c);
    }
    return minimum;
}

int cost(int n, int c, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return minCost(1, c, cuts);
}

// Memoization (Top down approach)
#include <bits/stdc++.h>
int minCost(int start, int end, vector<int> &cuts, vector<vector<int>> &dp) {
    if (start > end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }
    int minimum = INT_MAX;
    for (int i = start; i <= end; i++) {
        int c = (cuts[end + 1] - cuts[start - 1]) +
                minCost(start, i - 1, cuts, dp) + minCost(i + 1, end, cuts, dp);
        minimum = min(minimum, c);
    }
    return dp[start][end] = minimum;
}

int cost(int n, int c, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return minCost(1, c, cuts, dp);
}

// Bottom Up approach
#include <bits/stdc++.h>
int cost(int n, int c, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int start = c; start >= 1; start--) {
        for (int end = 1; end <= c; end++) {
            if (start > end) {
                dp[start][end] = 0;
            } else {
                int minimum = INT_MAX;
                for (int i = start; i <= end; i++) {
                    int c = (cuts[end + 1] - cuts[start - 1]) +
                            dp[start][i - 1] + dp[i + 1][end];
                    minimum = min(minimum, c);
                }
                dp[start][end] = minimum;
            }
        }
    }
    return dp[1][c];
}