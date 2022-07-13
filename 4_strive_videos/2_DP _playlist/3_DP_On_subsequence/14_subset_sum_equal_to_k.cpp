// Recursion
bool sstk(int index, int target, vector<int> &arr) {
    if (target == 0) {
        return true;
    }
    if (target < 0) {
        return false;
    }
    // it is possible to reach target if our array contains that element
    if (index == 0) {
        return arr[index] == target;
    }
    bool take = sstk(index - 1, target - arr[index], arr);
    bool doNotTake = sstk(index - 1, target, arr);
    return take || doNotTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return sstk(n - 1, k, arr);
}

// Recursion + memoization
bool sstk(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if (target == 0) {
        return true;
    }
    if (target < 0) {
        return false;
    }
    // it is possible to reach target if our array contains  that element
    if (index == 0) {
        return arr[index] == target;
    }
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    bool take = sstk(index - 1, target - arr[index], arr, dp);
    // if we found the subset with sum k no need to further check
    if (take) {
        dp[index][target] = 1;
        return true;
    }
    bool doNotTake = sstk(index - 1, target, arr, dp);
    dp[index][target] = doNotTake ? 1 : 0;
    return doNotTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return sstk(n - 1, k, arr, dp);
}

// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++) {
        for (int target = 0; target <= k; target++) {
            // if target is zero then must be true
            if (target == 0) {
                dp[i][0] = true;
            } else if (i == 0) {
                dp[0][arr[0]] = true;
            } else {
                bool take = false;
                bool doNotTake = false;
                if (i > 0 && target - arr[i] >= 0)
                    take = dp[i - 1][target - arr[i]];
                if (i > 0) doNotTake = dp[i - 1][target];
                dp[i][target] = take | doNotTake;
            }
        }
    }
    return dp[n - 1][k];
}

// Tabulation + Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k + 1, false);
    for (int i = 0; i < n; i++) {
        vector<bool> curr(k + 1, false);
        for (int target = 0; target <= k; target++) {
            // if target is zero then must be true
            if (target == 0) {
                curr[0] = true;
            } else if (i == 0) {
                curr[arr[0]] = true;
            } else {
                bool take = false;
                bool doNotTake = false;
                if (i > 0 && target - arr[i] >= 0) take = prev[target - arr[i]];
                if (i > 0) doNotTake = prev[target];
                curr[target] = take | doNotTake;
            }
        }
        prev = curr;
    }
    return prev[k];
}