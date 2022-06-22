/*
Chocolate Pickup

venice 14

Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some
chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many
chocolates as possible with the help of his friends. Initially, Alice is in the
top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ -
1) in the grid. Each of them can move from their current cell to the cells just
below them. When anyone passes from any cell, he will pick all chocolates in it,
and then the number of chocolates in that cell will become zero. If both stay in
the same cell, only one of them will pick the chocolates in it. If Alice or Bob
is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1).
They will always stay inside the ‘GRID’. Your task is to find the maximum number
of chocolates Ninja can collect with the help of his friends by following the
above rules. Example: Input: ‘R’ = 3, ‘C’ = 4 ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2,
2], [5, 6, 3, 5]] Output: 21

Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1)
-> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.

Initially Bob is at the position (0, 3) and he can follow the path (0, 3) ->
(1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.

Hence the total number of chocolates collected will be 12 + 9 = 21. there is no
other possible way to collect a greater number of chocolates than 21.
 */
// Recursion + memoization
int mc(int i, int ja, int jb, int n, int m, vector<vector<int>> &grid,
       vector<vector<vector<int>>> &dp) {
    if (ja < 0 || ja >= m || jb < 0 || jb >= m) return -1e9;

    if (i == n - 1) {
        if (ja == jb)
            return grid[i][ja];
        else
            return grid[i][ja] + grid[i][jb];
    }

    if (dp[i][ja][jb] != -1) return dp[i][ja][jb];

    int maxi = -1e8;
    for (int dja = -1; dja <= 1; dja++) {
        for (int djb = -1; djb <= 1; djb++) {
            int ans;
            if (ja == jb)
                ans =
                    grid[i][ja] + mc(i + 1, ja + dja, jb + djb, n, m, grid, dp);
            else
                ans = grid[i][ja] + grid[i][jb] +
                      mc(i + 1, ja + dja, jb + djb, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][ja][jb] = maxi;
}

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(m, -1)));
    return mc(0, 0, m - 1, n, m, grid, dp);
}
// Tabulation
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(m, -1)));
    for (int i = n - 1; i >= 0; i--) {
        for (int ja = 0; ja < m; ja++) {
            for (int jb = 0; jb < m; jb++) {
                if (i == n - 1) {
                    if (ja == jb) {
                        dp[i][ja][jb] = grid[i][ja];
                    } else {
                        dp[i][ja][jb] = grid[i][ja] + grid[i][jb];
                    }
                } else {
                    int maxi = -1e8;
                    for (int dja = -1; dja <= 1; dja++) {
                        for (int djb = -1; djb <= 1; djb++) {
                            int ans;
                            if (ja == jb)
                                ans = grid[i][ja];
                            else
                                ans = grid[i][ja] + grid[i][jb];

                            if (ja + dja >= 0 && ja + dja < m &&
                                jb + djb >= 0 && jb + djb < m) {
                                ans += dp[i + 1][ja + dja][jb + djb];
                            } else {
                                ans += -1e8;
                            }
                            maxi = max(maxi, ans);
                        }
                    }
                    dp[i][ja][jb] = maxi;
                }
            }
        }
    }
    return dp[0][0][m - 1];
}

// Tabulation +space optimization
// we can optimizar 3d DP->2d DP

int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> prev(m, vector<int>(m, 0));

    for (int i = n - 1; i >= 0; i--) {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int ja = 0; ja < m; ja++) {
            for (int jb = 0; jb < m; jb++) {
                if (i == n - 1) {
                    if (ja == jb) {
                        curr[ja][jb] = grid[i][ja];
                    } else {
                        curr[ja][jb] = grid[i][ja] + grid[i][jb];
                        ;
                    }
                } else {
                    int maxi = -1e8;
                    for (int dja = -1; dja <= 1; dja++) {
                        for (int djb = -1; djb <= 1; djb++) {
                            int ans;
                            if (ja == jb)
                                ans = grid[i][ja];
                            else
                                ans = grid[i][ja] + grid[i][jb];

                            if (ja + dja >= 0 && ja + dja < m &&
                                jb + djb >= 0 && jb + djb < m) {
                                ans += prev[ja + dja][jb + djb];
                            } else {
                                ans += -1e8;
                            }
                            maxi = max(maxi, ans);
                        }
                    }
                    curr[ja][jb] = maxi;
                }
            }
        }
        prev = curr;
    }
    return prev[0][m - 1];
}