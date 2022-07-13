/*
Maximum Path Sum in the matrix

venice 13

You have been given an N*M matrix filled with integer numbers, find the maximum
sum that can be obtained from a path starting from any cell in the first row to
any cell in the last row. From a cell in a row, you can move to another cell
directly below that row, or diagonally below left or right. So from a particular
cell (row, col), we can move in three directions i.e. Down: (row+1,col) Down
left diagonal: (row+1,col-1) Down right diagonal: (row+1, col+1)

2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
1 2 2 1
3 3
10 2 3
3 7 2
8 1 5
Output 1 :
105
25
Explanation Of Input 1 :
In the first test case for the given matrix,

The maximum path sum will be 2->100->1->2, So the sum is 105(2+100+1+2).

In the second test case for the given matrix, the maximum path sum will be
10->7->8, So the sum is 25(10+7+8).
 */
// Recursion + Memoization
int gmps(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if (i < 0 | j<0 | j> matrix[0].size() - 1) {
        return -1e8;
    }
    if (i == 0) {
        return matrix[0][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = matrix[i][j] + gmps(i - 1, j, matrix, dp);
    int leftUpDiagonal = matrix[i][j] + gmps(i - 1, j - 1, matrix, dp);
    int rightUpDiagonal = matrix[i][j] + gmps(i - 1, j + 1, matrix, dp);
    return dp[i][j] = max(up, max(leftUpDiagonal, rightUpDiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxPathSum = -1e8;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < m; i++) {
        int pathSum = gmps(n - 1, i, matrix, dp);
        maxPathSum = max(maxPathSum, pathSum);
    }
    return maxPathSum;
}

// Tabulation
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                // handling base case
                dp[0][j] = matrix[0][j];
            } else {
                int up = matrix[i][j] + dp[i - 1][j];
                int leftUpDiagonal = -1e8;
                if (j > 0) leftUpDiagonal = matrix[i][j] + dp[i - 1][j - 1];
                int rightUpDiagonal = -1e8;
                if (j <= m - 2)  // j can atmost go till m-1 ...so add one more
                                 // two it we must have m-2 initially
                    rightUpDiagonal = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = max(up, max(leftUpDiagonal, rightUpDiagonal));
            }
        }
    }
    int maxPathSum = -1e8;
    for (int j = 0; j < m; j++) {
        maxPathSum = max(maxPathSum, dp[n - 1][j]);
    }
    return maxPathSum;
}

// Tabulation + space Optimization
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                curr[j] = matrix[0][j];
            } else {
                int up = matrix[i][j] + prev[j];
                int leftUpDiagonal = -1e8;
                if (j > 0) leftUpDiagonal = matrix[i][j] + prev[j - 1];
                int rightUpDiagonal = -1e8;
                if (j <= m - 2)  // j can atmost go till m-1 ...so add one more
                                 // two it we must have m-2 initially
                    rightUpDiagonal = matrix[i][j] + prev[j + 1];
                curr[j] = max(up, max(leftUpDiagonal, rightUpDiagonal));
            }
        }
        prev = curr;
    }
    int maxPathSum = -1e8;
    for (int j = 0; j < m; j++) {
        maxPathSum = max(maxPathSum, prev[j]);
    }
    return maxPathSum;
}