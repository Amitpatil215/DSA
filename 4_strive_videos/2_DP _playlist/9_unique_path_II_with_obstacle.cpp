// Unique Path II -> Maze with obstacles
// venice 11
/*
Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique
paths to reach the right-bottom cell from the top-left cell. A cell in the given
maze has a value '-1' if it is a blockage or dead-end, else 0. From a given
cell, we are allowed to move to cells (i+1, j) and (i, j+1) only. Since the
answer can be large, print it modulo 10^9 + 7. For Example : Consider the maze
below : 0 0 0 0 -1 0 0 0 0

There are two ways to reach the bottom left corner -

(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)

Hence the answer for the above test case is 2.


Sample Input 1 :
2
2 2
0 0
0 0
3 3
0 0 0
0 -1 0
0 0 0
Sample Output 1 :
2
2
Explanation For Sample Output 1 :
For the first test case, there are two possible paths to reach (2, 2) from (1,
1) : (1, 1) -> (1, 2) -> (2, 2) (1, 1) -> (2, 1) -> (2, 2)

For the second test case, there are two ways to reach the bottom left corner -
(1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
(1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
 */

// Recursion
int mo(int i, int j, vector<vector<int>> &mat) {
    long long m = 1000000007;
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    // handling dead end
    if (mat[i][j] == -1) {
        return 0;
    }
    int up = mo(i - 1, j, mat, dp) % m;
    int left = mo(i, j - 1, mat, dp) % m;
    return (up + left) % m;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    return mo(n - 1, m - 1, mat);
}

// Recusrsion + Memoization
int mo(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    long long m = 1000000007;
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    // handling dead end
    if (mat[i][j] == -1) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = mo(i - 1, j, mat, dp) % m;
    int left = mo(i, j - 1, mat, dp) % m;
    return dp[i][j] = (up + left) % m;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return mo(n - 1, m - 1, mat, dp);
}

// Tabulation
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    long long mod = 1000000007;
    vector<vector<int>> dp(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else if (i >= 0 && j >= 0 && mat[i][j] == -1) {
                // handling dead end
                dp[i][j] = 0;
            } else {
                int up = 0;
                int left = 0;
                if (i > 0) {
                    up = dp[i - 1][j] % mod;
                }
                if (j > 0) {
                    left = dp[i][j - 1] % mod;
                }
                dp[i][j] = (up + left) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// Tabulation + space optimization
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
    long long mod = 1000000007;
    // storing prev row in it, and initilized with 0
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                curr[j] = 1;
            } else if (i >= 0 && j >= 0 && mat[i][j] == -1) {
                // handling dead end
                curr[j] = 0;
            } else {
                int up = 0;
                int left = 0;
                if (i > 0) {
                    up = prev[j] % mod;
                }
                if (j > 0) {
                    left = curr[j - 1] % mod;
                }
                curr[j] = (up + left) % mod;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}