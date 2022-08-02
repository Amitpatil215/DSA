/*
Egg Dropping Puzzle

https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

This problem is part of GFG SDE Sheet. Click here to view more.

You are given N identical eggs and you have access to a K-floored building from
1 to K.

There exists a floor f where 0 <= f <= K such that any egg dropped at a floor
higher than f will break, and any egg dropped at or below floor f will not
break. There are few rules given below.

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor
below. If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with certainty
what the value of f is.

For more description on this problem see wiki page

Example 1:

Input:
N = 1, K = 2
Output: 2
Explanation:
1. Drop the egg from floor 1. If it
   breaks, we know that f = 0.
2. Otherwise, drop the egg from floor 2.
   If it breaks, we know that f = 1.
3. If it does not break, then we know f = 2.
4. Hence, we need at minimum 2 moves to
   determine with certainty what the value of f is.
Example 2:

Input:
N = 2, K = 10
Output: 4
Your Task:
Complete the function eggDrop() which takes two positive integer N and K as
input parameters and returns the minimum number of attempts you need in order to
find the critical floor.

Expected Time Complexity : O(N*(K^2))
Expected Auxiliary Space: O(N*K)

Constraints:
1<=N<=200
1<=K<=200
 */

// ? Memoization (Giving TLE)

class Solution {
   public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eg(int n, int k, vector<vector<int>> &dp) {
        // n -> no of eggs
        //  k-> no of floors in  building

        // base case
        // if there is only one egg then we need to check for every florr
        // starting from the ground floor in worst case the egg droped from
        // top floor will break
        if (n == 1) {
            return k;
        }

        if (k == 0 || k == 1) {
            return k;
        }

        if (dp[n][k] != -1) {
            return dp[n][k];
        }

        int minAttempts = INT_MAX;
        for (int i = 1; i <= k; i++) {
            // min no of attempts if egg is thrown from //ith efloor
            int temp = 1 + max(eggDrop(n - 1, i - 1), eggDrop(n, k - i));
            minAttempts = min(minAttempts, temp);
        }
        return dp[n][k] = minAttempts;
    }
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return eg(n, k, dp);
    }
};

//? Tabulation

class Solution {
   public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eg(int n, int k, vector<vector<int>> &dp) {
        // n -> no of eggs
        //  k-> no of floors in  building

        // base case
        // if there is only one egg then we need to check for every florr
        // starting from the ground floor in worst case the egg droped from
        // top floor will break
        if (n == 1) {
            return k;
        }

        if (k == 0 || k == 1) {
            return k;
        }

        if (dp[n][k] != -1) {
            return dp[n][k];
        }

        int minAttempts = INT_MAX;
        for (int i = 1; i <= k; i++) {
            // min no of attempts if egg is thrown from //ith efloor
            int temp = 1 + max(eggDrop(n - 1, i - 1), eggDrop(n, k - i));
            minAttempts = min(minAttempts, temp);
        }
        return dp[n][k] = minAttempts;
    }
    int eggDrop(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int egg = 1; egg <= n; egg++) {
            for (int floor = 0; floor <= k; floor++) {
                if (egg == 1) {
                    // We always need j trials for one egg
                    // and j floors.
                    dp[egg][floor] = floor;
                } else if (floor == 0 || floor == 1) {
                    // We need one trial for one floor and 0
                    // trials for 0 floors
                    dp[egg][floor] = floor;
                } else {
                    int minAttempts = INT_MAX;
                    for (int i = 1; i <= floor; i++) {
                        // min no of attempts if egg is thrown from //ith efloor
                        int temp =
                            1 + max(dp[egg - 1][i - 1], dp[egg][floor - i]);
                        minAttempts = min(minAttempts, temp);
                    }
                    dp[egg][floor] = minAttempts;
                }
            }
        }
        return dp[n][k];
    }
};
