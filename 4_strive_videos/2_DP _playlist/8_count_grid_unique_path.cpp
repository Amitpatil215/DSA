// Count Grid Unique Path
// venice 8

/*
You are present at point ‘A’ which is the top-left cell of an M X N matrix, your
destination is point ‘B’, which is the bottom-right cell of the same matrix.
Your task is to find the total number of unique paths from point ‘A’ to point
‘B’.In other words, you will be given the dimensions of the matrix as integers
‘M’ and ‘N’, your task is to find the total number of unique paths from the cell
MATRIX[0][0] to MATRIX['M' - 1]['N' - 1]. To traverse in the matrix, you can
either move Right or Down at each step. For example in a given point MATRIX[i]
[j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].

Sample Input 1:
2
2 2
1 1
Sample Output 1:
2
1

Explanation Of Sample Output 1:
In test case 1, we are given a 2 x 2 matrix, to move from matrix[0][0] to
matrix[1][1] we have the following possible paths.

Path 1 = (0, 0) -> (0, 1) -> (1, 1)
Path 2 = (0, 0) -> (1, 0) -> (1, 1)

Hence a total of 2 paths are available, so the output is 2.

In test case 2, we are given a 1 x 1 matrix, hence we just have a single cell
which is both the starting and ending point. Hence the output is 1.
 */

// Recursion
#include <bits/stdc++.h>
int upCount(int i, int j) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    int up = upCount(i - 1, j);
    int left = upCount(i, j - 1);
    return up + left;
}
int uniquePaths(int m, int n) { return upCount(m - 1, n - 1); }

// Recursion + memoization
#include <bits/stdc++.h>
int upCount(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 && j == 0) {
        return 1;
    }
    if (i < 0 || j < 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = upCount(i - 1, j, dp);
    int left = upCount(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return upCount(m - 1, n - 1, dp);
}

//  Tabulation
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                int up = 0;
                int left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}

// Tabulation + Space Optimization
#include <bits/stdc++.h>
int uniquePaths(int m, int n) {
    vector<int> prevRow(n, 0);
    for (int i = 0; i < m; i++) {
        vector<int> currRow(n, 0);
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                currRow[j] = 1;
            } else {
                int up = 0;
                int left = 0;
                if (i > 0) up = prevRow[j];
                if (j > 0) left = currRow[j - 1];

                currRow[j] = up + left;
            }
        }
        prevRow = currRow;
    }
    return prevRow[n - 1];
}