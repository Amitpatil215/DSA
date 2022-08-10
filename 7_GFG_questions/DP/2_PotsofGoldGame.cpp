/*
Pots of Gold Game

MediumAccuracy: 47.59%Submissions: 9519Points: 4
Two players X and Y are playing a game in which there are pots of gold arranged
in a line, each containing some gold coins. They get alternating turns in which
the player can pick a pot from one of the ends of the line. The winner is the
player who has a higher number of coins at the end. The objective is to maximize
the number of coins collected by X, assuming Y also plays optimally.

Return the maximum coins X could get while playing the game. Initially, X starts
the game.

Example 1:

Input:
N = 4
Q[] = {8, 15, 3, 7}
Output: 22
Explanation: Player X starts and picks 7. Player Y
picks the pot containing 8. Player X picks the pot
containing 15. Player Y picks 3.
Total coins collected by X = 7 + 15 = 22.
Example 2:

Input:
N = 4
A[] = {2, 2, 2, 2}
Output: 4

Your Task:
You don't need to read input or print anything. Your task is to complete the
function maxCoins() which takes an integer N and an array of size N  as input
and returns the maximum coins collected by player X.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N2)


Constraints:
1 <= N <= 500
1 <= A[i] <= 103 */

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int mc(int left, int right, vector<int>& coins, vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        int chooseLeft = coins[left] + min(mc(left + 1, right - 1, coins, dp),
                                           mc(left + 2, right, coins, dp));
        int chooseRight = coins[right] + min(mc(left + 1, right - 1, coins, dp),
                                             mc(left, right - 2, coins, dp));
        return dp[left][right] = max(chooseLeft, chooseRight);
    }

    int maxCoins(vector<int>& A, int n) {
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return mc(0, n - 1, A, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}

// } Driver Code Ends