/*
Partition a set into two subsets such that the difference of subset sums is
minimum. (all non negative elements)

venice 15

Problem Statement
You are given an array containing N non-negative integers. Your task is to
partition this array into two subsets such that the absolute difference between
subset sums is minimum. You just need to find the minimum absolute difference
considering any valid division of the array elements. Note:
1. Each element of the array should belong to exactly one of the subset.

2. Subsets need not be contiguous always. For example, for the array : {1,2,3},
some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.

3. Subset-sum is the sum of all the elements in that subset.

Sample Input 1:
1
3
8 6 5
Sample Output 1:
3

Explanation For Sample Input 1:
We can partition the given array into {8} and {6,5}, as this will give us the
minimum possible absolute difference i.e (11-8=3) in this cas
 */

// Tabulation Approach
#include <bits/stdc++.h>
vector<bool> subsetSumHavingTargetK(int n, int k, vector<int>& nums) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            if (target == 0) {
                dp[i][0] = true;
            } else if (i == 0 && nums[0] <= k + 1) {
                dp[0][nums[0]] = true;
            } else {
                bool consider = false;
                bool doNotConsider = false;
                if (i > 0 && target - nums[i] >= 0) {
                    consider = dp[i - 1][target - nums[i]];
                }
                if (i > 0) {
                    doNotConsider = dp[i - 1][target];
                }
                dp[i][target] = consider || doNotConsider;
            }
        }
    }
    return dp[n - 1];
}

int minSubsetSumDifference(vector<int>& nums, int n) {
    int sum = 0;
    for (auto x : nums) {
        sum += x;
    }
    vector<bool> everyPossibleTargetSum = subsetSumHavingTargetK(n, sum, nums);
    int minDiff = INT_MAX;
    for (int i = 0; i <= (everyPossibleTargetSum.size() / 2) + 1; i++) {
        if (everyPossibleTargetSum[i]) {
            int subset1Sum = i;
            int subset2Sum = sum - subset1Sum;
            minDiff = min(minDiff, abs(subset1Sum - subset2Sum));
        }
    }
    return minDiff;
}