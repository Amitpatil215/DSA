/*
115. Distinct Subsequences

venice 30

Given two strings s and t, return the number of distinct subsequences of s which
equals t.

A string's subsequence is a new string formed from the original string by
deleting some (can be none) of the characters without disturbing the remaining
characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while
"AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag


Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
 */

// Recursion
class Solution {
   public:
    int nd(int index1, int index2, string &str1, string &str2) {
        // we exhausted the target string
        if (index2 < 0) {
            return 1;
        }
        // we exhausted original string but not target
        if (index1 < 0) {
            return 0;
        }

        if (str1[index1] == str2[index2]) {
            return nd(index1 - 1, index2 - 1, str1, str2) +
                   nd(index1 - 1, index2, str1, str2);
        } else {
            return nd(index1 - 1, index2, str1, str2);
        }
    }

    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        return nd(l1 - 1, l2 - 1, s, t);
    }
};

// Recursion + memoization
class Solution {
   public:
    int nd(int index1, int index2, string &str1, string &str2,
           vector<vector<int>> &dp) {
        // we exhausted the target string
        if (index2 < 0) {
            return 1;
        }
        // we exhausted original string but not target
        if (index1 < 0) {
            return 0;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        if (str1[index1] == str2[index2]) {
            return dp[index1][index2] =
                       nd(index1 - 1, index2 - 1, str1, str2, dp) +
                       nd(index1 - 1, index2, str1, str2, dp);
        } else {
            return dp[index1][index2] = nd(index1 - 1, index2, str1, str2, dp);
        }
    }

    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return nd(l1 - 1, l2 - 1, s, t, dp);
    }
};

// Tabulation
class Solution {
   public:
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        string str1 = s;
        string str2 = t;
        int mod = (1e9 + 7);
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        // for base case
        for (int index1 = 0; index1 <= l1; index1++) {
            // we got our sbsequequence as we are follwoing 1 based indexing in
            // this if index2==0
            dp[index1][0] = 1;
        }

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {
                if (str1[index1 - 1] == str2[index2 - 1]) {
                    int take = dp[index1 - 1][index2 - 1];
                    int doNotTake = dp[index1 - 1][index2];
                    dp[index1][index2] = (take + doNotTake) % mod;
                } else {
                    dp[index1][index2] = dp[index1 - 1][index2];
                }
            }
        }
        return dp[l1][l2];
    }
};

// Tabulation  + space Optimization
class Solution {
   public:
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        string str1 = s;
        string str2 = t;
        int mod = (1e9 + 7);

        vector<int> prev(l2 + 1, 0);
        vector<int> curr(l2 + 1, 0);

        // for base case
        // we got our sbsequequence as we are follwoing 1 based indexing in this
        // if index2==0
        prev[0] = 1;
        curr[0] = 1;

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = 1; index2 <= l2; index2++) {
                if (str1[index1 - 1] == str2[index2 - 1]) {
                    int take = prev[index2 - 1];
                    int doNotTake = prev[index2];
                    curr[index2] = (take + doNotTake) % mod;
                } else {
                    curr[index2] = prev[index2];
                }
            }
            prev = curr;
        }
        return prev[l2];
    }
};

// Tabulation + 1D Space optimization
class Solution {
   public:
    int numDistinct(string s, string t) {
        int l1 = s.size();
        int l2 = t.size();
        string str1 = s;
        string str2 = t;
        int mod = (1e9 + 7);

        vector<int> prev(l2 + 1, 0);

        // for base case
        // we got our sbsequequence as we are follwoing 1 based indexing in this
        // if index2==0
        prev[0] = 1;

        for (int index1 = 1; index1 <= l1; index1++) {
            for (int index2 = l2; index2 >= 1; index2--) {
                if (str1[index1 - 1] == str2[index2 - 1]) {
                    int take = prev[index2 - 1];
                    int doNotTake = prev[index2];
                    prev[index2] = (take + doNotTake) % mod;
                } else {
                    prev[index2] = prev[index2];
                }
            }
        }
        return prev[l2];
    }
};