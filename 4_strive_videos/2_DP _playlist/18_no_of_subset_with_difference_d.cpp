/*
Partitions With Given Difference

venice 17

Given an array ‘ARR’, partition it into two subsets (possibly empty) such that
their union is the original array. Let the sum of the elements of these two
subsets be ‘S1’ and ‘S2’. Given a difference ‘D’, count the number of partitions
in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’
and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo
‘10^9 + 7’.

For Example :

If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2
+ 1) - (5) = 3 Partition 2: {5, 2, 1}, {5}. The subset difference between subset
sum is: (5 + 2 + 1) - (5) = 3 These two partitions are different because, in the
1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains
5 from index 2.

Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 50
0 ≤ D ≤ 2500
0 ≤ ARR[i] ≤ 50

Since the answer may be too large, return it modulo ‘10^9 + 7’.

Time limit: 1 sec

 */
int mod = (int)(1e9 + 7);
int cp(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            if (i == 0) {
                // if target sum is 0 and array element is also 0 then we can
                // take zero or dont take it
                if (arr[0] == 0) {
                    dp[0][0] = 2;
                } else
                    // if target sum is 0 but array element is not 0 , that
                    // means we hace reached to target
                    dp[0][0] = 1;
                // if element is target itself then we should take it to make
                // target sum 0
                if (target == arr[0]) {
                    dp[0][arr[0]] = 1;
                }
            } else {
                int take = 0;
                int doNotTake = 0;
                if (i > 0 && target - arr[i] >= 0) {
                    take = dp[i - 1][target - arr[i]];
                }
                if (i > 0) {
                    doNotTake = dp[i - 1][target];
                }
                dp[i][target] = (take + doNotTake) % mod;
            }
        }
    }
    return dp[n - 1][k];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for (auto x : arr) {
        sum = (sum + x) % mod;
    }
    if (sum - d >= 0 && (sum - d) % 2 == 0) {
        return cp(n, (sum - d) / 2, arr);
    } else {
        return 0;
    }
}
