// Triangle
// Venice 12
/*
You are given a triangular array/list 'TRIANGLE'. Your task is to return the
minimum path sum to reach from the top to the bottom row. The triangle array
will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if
you are at index j in row i, then you can move to i or i + 1 index in row j + 1
in each step. For Example : If the array given is 'TRIANGLE' = [[1], [2,3],
[3,6,7], [8,9,6,1]] the triangle array will look like:

1
2,3
3,6,7
8,9,6,10

For the given triangle array the minimum sum path would be 1->2->3->8. Hence the
answer would be 14.
 */

// Recursion
int mps(int i, int j, vector<vector<int>>& triangle, int totalNoOfRows) {
    if (i == totalNoOfRows - 1) {
        return triangle[i][j];
    }
    int down = triangle[i][j] + mps(i + 1, j, triangle, totalNoOfRows);
    int diagonal = triangle[i][j] + mps(i + 1, j + 1, triangle, totalNoOfRows);
    return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    return mps(0, 0, triangle, n);
}

// Recursion + memoization
int mps(int i, int j, vector<vector<int>>& triangle, int totalNoOfRows,
        vector<vector<int>>& dp) {
    if (i == totalNoOfRows - 1) {
        return triangle[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int down = triangle[i][j] + mps(i + 1, j, triangle, totalNoOfRows, dp);
    int diagonal =
        triangle[i][j] + mps(i + 1, j + 1, triangle, totalNoOfRows, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<vector<int>> dp(n - 1, vector<int>(n, -1));
    return mps(0, 0, triangle, n, dp);
}

// Tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    // decleare a (0 to n-1) * (0 to n-1) size dp array for row and column
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // loop from last row to the 0th row
    for (int i = n - 1; i >= 0; i--) {
        // for every row there gonna be i to 0 columns to be filled
        for (int j = i; j >= 0; j--) {
            // base case for last row
            if (i == n - 1) {
                dp[i][j] = triangle[i][j];
            } else {
                // copy code from recursion
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
    }
    return dp[0][0];
}

// Tabulation + Space optimization
int minimumPathSum(vector<vector<int>>& triangle, int n) {
    vector<int> prev(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        vector<int> curr(n, 0);
        for (int j = i; j >= 0; j--) {
            if (i == n - 1) {
                curr[j] = triangle[i][j];
            } else {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                curr[j] = min(down, diagonal);
            }
        }
        prev = curr;
    }
    return prev[0];
}