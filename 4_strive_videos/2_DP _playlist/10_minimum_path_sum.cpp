// Minimum Path sum

// Venice 11
/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N'
rows and 'M' columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' -
1) which minimizes the sum of the cost of all the numbers along the path. You
need to tell the minimum sum of that path. Note: You can only move down or right
at any point in time.


Constraints:
1 <= T <= 100
1 <= N, M <= 10^2
1 <= GRID[i][j] <= 10^5

Where 'GRID[i][j]' denotes the value of the cell in the matrix.

Time limit: 1 sec
Sample Input 1:
2
2 3
5 9 6
11 5 2
1 1
5
Sample Output 1:
21
5
Explanation For Sample Output 1:
In test case 1, Consider a grid of 2*3:

For this the grid the path with minimum value is (0,0) -> (0,1) -> (1,1) ->
(1,2). And the sum along this path is 5 + 9 +5 + 2 = 21. So the ans is 21.

 */
// Recursion
#include <bits/stdc++.h>
int msp(int i, int j, vector<vector<int>> &grid) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        return 1e9;
    }
    int up = grid[i][j] + msp(i - 1, j, grid);
    int left = grid[i][j] + msp(i, j - 1, grid);
    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    return msp(grid.size() - 1, grid[0].size() - 1, grid);
}

// Recursion + memoization
#include <bits/stdc++.h>
int msp(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if (i == 0 && j == 0) {
        return grid[i][j];
    }
    if (i < 0 || j < 0) {
        return 1e9;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int up = grid[i][j] + msp(i - 1, j, grid, dp);
    int left = grid[i][j] + msp(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return msp(grid.size() - 1, grid[0].size() - 1, grid, dp);
}

// Tabulation
#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = grid[i][j];
            } else {
                int up = grid[i][j];
                if (i > 0) {
                    up += dp[i - 1][j];
                } else {
                    up += 1e9;
                }

                int left = grid[i][j];
                if (j > 0) {
                    left += dp[i][j - 1];
                } else {
                    left += 1e9;
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n - 1][m - 1];
}

// Tabulation + Space Optimization
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<int> prev(m, 1e9);

    for (int i = 0; i < n; i++) {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                curr[j] = grid[i][j];
            } else {
                int up = grid[i][j];
                if (i > 0) {
                    up += prev[j];
                } else {
                    up += 1e9;
                }
                int left = grid[i][j];

                if (j > 0) {
                    left += curr[j - 1];
                } else {
                    left += 1e9;
                }
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}