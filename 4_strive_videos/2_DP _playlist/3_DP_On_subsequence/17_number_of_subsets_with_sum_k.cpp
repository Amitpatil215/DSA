
/*
Number Of Subsets

venice 17
Problem Statement
You are given an array (0-based indexing) of positive integers and you have to
tell how many different ways of selecting the elements from the array are there
such that the sum of chosen elements is equal to the target number “tar”. Note:
Two ways are considered different if sets of indexes of elements chosen by these
ways are different.

Input is given such that the answer will fit in a 32-bit integer.
For Example:
If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of
possible ways are: {1, 2} {3} {1, 2} Hence the output will be 3.

Sample Input 1 :
2
4 3
1 2 2 3
2 3
1 2
Sample Output 1 :
 3
 1
Explanation For Sample Output 1:
For the first test case, N = 4 and tar = 3 and array elements are [1, 2, 2, 2,3]
then the number of possible ways of making sum = 5 are: {1,2} {3} {1,2}

Hence the output will be 3.

For the second test case, N = 2 and tar = 3 and array elements are [1, 2], there
is only one way of making sum = 3 which is {1,2}.

Hence the output will be 1.
 */
#include <bits/stdc++.h>

int fw(int n, int k, vector<int> &nums) {
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            if (target == 0) {
                dp[i][target] = 1;
            } else if (i == 0 && nums[0] <= k + 1) {
                dp[0][nums[0]] = 1;
            } else {
                int picked = 0;
                int notPicked = 0;
                if (i > 0 && target - nums[i] >= 0) {
                    picked = dp[i - 1][target - nums[i]];
                }
                if (i > 0) {
                    notPicked = dp[i - 1][target];
                }
                dp[i][target] = picked + notPicked;
            }
        }
    }
    return dp[n - 1][k];
}

int findWays(vector<int> &nums, int tar) { return fw(nums.size(), tar, nums); }

// Tabulation + Space Optimization
#include <bits/stdc++.h>

int fw(int n, int k, vector<int> &nums) {
    vector<int> prev(k + 1, 0);
    for (int i = 0; i < n; i++) {
        vector<int> curr(k + 1, 0);
        for (int target = 0; target <= k; target++) {
            if (target == 0) {
                curr[target] = 1;
            } else if (i == 0 && nums[0] <= k + 1) {
                curr[nums[0]] = 1;
            } else {
                int picked = 0;
                int notPicked = 0;
                if (i > 0 && target - nums[i] >= 0) {
                    picked = prev[target - nums[i]];
                }
                if (i > 0) {
                    notPicked = prev[target];
                }
                curr[target] = picked + notPicked;
            }
        }
        prev = curr;
    }
    return prev[k];
}

int findWays(vector<int> &nums, int tar) { return fw(nums.size(), tar, nums); }