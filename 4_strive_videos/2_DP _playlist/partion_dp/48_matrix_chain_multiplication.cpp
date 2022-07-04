/*
Matrix Chain Multiplication

vencie 46

Problem Statement
Given a chain of matrices A1, A2, A3,.....An. Your task is to find out the
minimum cost to multiply these matrices. The cost of matrix multiplication is
defined as the number of scalar multiplications. A Chain of matrices A1, A2,
A3,.....An is represented by a sequence of numbers in an array ‘arr’ where the
dimension of 1st matrix is equal to arr[0] * arr[1] , 2nd matrix is arr[1] *
arr[2], and so on.

For example: For arr[ ] = { 10, 20, 30, 40}, matrix A1 = [10* 20],
A2 = [20 * 30], A3 = [30 * 40]

Constraints:
1 <= T <= 5
2 <= N <= 100
1 <= arr[i] <= 400

Time Limit: 1 sec.

? Sample Input 1:
2
4
4 5 3 2
4
10 15 20 25
Sample Output 1:
8000
70
Sample Output Explanation 1:
In the first test case, there are three matrices of dimensions A = [4 5], B = [5
3] and C = [3 2]. The most efficient order of multiplication is A * ( B * C).
Cost of ( B * C ) = 5 * 3 * 2 = 30  and (B * C) = [5 2] and A * (B * C) = [ 4 5]
* [5 2] = 4 * 5 * 2 = 40. So the overall cost is equal to 30 + 40 =70.

In the second test case, there are two ways to multiply the chain - A1*(A2*A3)
or (A1*A2)*A3.

If we multiply in order- A1*(A2*A3), then the number of multiplications required
is 11250.

If we multiply in order- (A1*A2)*A3, then the number of multiplications required
is 8000.

Thus a minimum number of multiplications required is 8000.

? Sample Input 2:
1
4
1 4 3 2
Sample Output 2:
18

Explanation of Sample Output 2:
In the first test case, there are three matrices of dimensions A = [1 4], B = [4
3] and C = [3 2]. The most efficient order of multiplication is (A *  B) * C .

Scalar multiplication of matrix with dimension 10 * 20 is equal to 200.
 */

// Recursion
#include <bits/stdc++.h>
int mm(int start, int end, vector<int> &arr, int n) {
    // if we left with only one matrix
    if (start == end) {
        return 0;
    }
    int minOper = 1e9;
    for (int k = start; k <= end - 1; k++) {
        int operations = (arr[start - 1] * arr[k] * arr[end]) +
                         mm(start, k, arr, n) + mm(k + 1, end, arr, n);
        minOper = min(minOper, operations);
    }
    return minOper;
}

int matrixMultiplication(vector<int> &arr, int N) {
    return mm(1, N - 1, arr, N);
}

// Memoization
#include <bits/stdc++.h>
int mm(int start, int end, vector<int> &arr, int n, vector<vector<int>> &dp) {
    // if we left with only one matrix
    if (start == end) {
        return 0;
    }
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    int minOper = 1e9;
    for (int k = start; k <= end - 1; k++) {
        int operations = (arr[start - 1] * arr[k] * arr[end]) +
                         mm(start, k, arr, n, dp) + mm(k + 1, end, arr, n, dp);
        minOper = min(minOper, operations);
    }
    return dp[start][end] = minOper;
}

int matrixMultiplication(vector<int> &arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return mm(1, N - 1, arr, N, dp);
}

// Tabulation
#include <bits/stdc++.h>
int matrixMultiplication(vector<int> &arr, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int start = n - 1; start >= 1; start--) {
        for (int end = start + 1; end <= n - 1; end++) {
            if (start == end) {
                dp[start][end] = 0;
            } else {
                int minOper = 1e9;
                for (int k = start; k <= end - 1; k++) {
                    int operations = (arr[start - 1] * arr[k] * arr[end]) +
                                     dp[start][k] + dp[k + 1][end];
                    minOper = min(minOper, operations);
                }
                dp[start][end] = minOper;
            }
        }
    }
    return dp[1][n - 1];
}