/*
Target Sum

venice 20

Problem Statement
You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your
task is to build an expression out of an array by adding one of the symbols '+'
and '-' before each integer in an array, and then by concatenating all the
integers, you want to achieve a target. You have to return the number of ways
the target can be achieved. For Example : You are given the array ‘ARR’ = [1, 1,
1, 1, 1], ‘TARGET’ = 3. The number of ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to make. Hence the answer is 5.

Sample Input 1 :
2
5 3
1 1 1 1 1
4 3
1 2 3 1
Sample Output 2 :
5
2
Explanation For Sample Input 1 :
For the first test case, ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of
ways this target can be achieved is:
1. -1 + 1 + 1 + 1 + 1 = 3
2. +1 - 1 + 1 + 1 + 1 = 3
3. +1 + 1 - 1 + 1 + 1 = 3
4. +1 + 1 + 1 - 1 + 1 = 3
5. +1 + 1 + 1 + 1 - 1 = 3
These are the 5 ways to get the target. Hence the answer is 5.

For the second test case, ‘ARR’ = [1, 2, 3, 1]. ‘TARGET’ = 3, The number of ways
this target can be achieved is:
1. +1 - 2 + 1 + 3 = 3
2. -1 + 2 - 1 + 3 = 3
These are the 3 ways to get the target. Hence the answer is 2.
Sample Input 2 :
2
3 2
1 2 3
2 0
1 1
Sample Output 2 :
1
2
 */

// Recursion
int ts(int index, int target, vector<int>& arr) {
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 && arr[0] != 0) return 1;
        if (target == arr[0]) return 1;
        return 0;
    }
    int take = 0;
    int doNotTake = 0;
    if (target - arr[index] >= 0) {
        take = ts(index - 1, target - arr[index], arr);
    }
    doNotTake = ts(index - 1, target, arr);
    return take + doNotTake;
}

int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for (auto x : arr) {
        totalSum += x;
    }
    if ((totalSum - target) >= 0 && (totalSum - target) % 2 == 0) {
        return ts(n - 1, (totalSum - target) / 2, arr);
    } else {
        return 0;
    }
}

// recursion + memoization
int ts(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 && arr[0] != 0) return 1;
        if (target == arr[0]) return 1;
        return 0;
    }
    if (dp[index][target] != -1) {
        return dp[index][target];
    }
    int take = 0;
    int doNotTake = 0;
    if (target - arr[index] >= 0) {
        take = ts(index - 1, target - arr[index], arr, dp);
    }
    doNotTake = ts(index - 1, target, arr, dp);
    return dp[index][target] = take + doNotTake;
}

int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for (auto x : arr) {
        totalSum += x;
    }
    if ((totalSum - target) >= 0 && (totalSum - target) % 2 == 0) {
        int actualTarget = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(actualTarget + 1, -1));
        return ts(n - 1, actualTarget, arr, dp);
    } else {
        return 0;
    }
}

// Tabulation
int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for (auto x : arr) {
        totalSum += x;
    }
    if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) {
        return 0;
    }
    int actualTarget = (totalSum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(actualTarget + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int tar = 0; tar <= actualTarget; tar++) {
            if (i == 0) {
                if (arr[0] == 0) dp[0][0] = 2;
                if (arr[0] != 0) dp[0][0] = 1;
                if (tar == arr[0]) dp[0][arr[0]] = 1;
            } else {
                int take = 0;
                int doNotTake = 0;
                if (tar - arr[i] >= 0) {
                    take = dp[i - 1][tar - arr[i]];
                }
                doNotTake = dp[i - 1][tar];
                dp[i][tar] = take + doNotTake;
            }
        }
    }
    return dp[n - 1][actualTarget];
}

// Tabulation + space optimization
int targetSum(int n, int target, vector<int>& arr) {
    int totalSum = 0;
    for (auto x : arr) {
        totalSum += x;
    }
    if ((totalSum - target) < 0 || (totalSum - target) % 2 != 0) {
        return 0;
    }
    int actualTarget = (totalSum - target) / 2;

    vector<int> prev(actualTarget + 1, 0);
    vector<int> curr(actualTarget + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int tar = 0; tar <= actualTarget; tar++) {
            if (i == 0) {
                if (arr[0] == 0) curr[0] = 2;
                if (arr[0] != 0) curr[0] = 1;
                if (tar == arr[0]) curr[arr[0]] = 1;
            } else {
                int take = 0;
                int doNotTake = 0;
                if (tar - arr[i] >= 0) {
                    take = prev[tar - arr[i]];
                }
                doNotTake = prev[tar];
                curr[tar] = take + doNotTake;
            }
        }
        prev = curr;
    }
    return prev[actualTarget];
}