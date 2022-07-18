/*
Longest Common Subsequence

venice 25

Problem Statement
You have been given two Strings “STR1” and “STR2” of characters. Your task is to
find the length of the longest common subsequence. A String ‘a’ is a subsequence
of a String ‘b’ if ‘a’ can be obtained from ‘b’ by deletion of several
(possibly, zero or all) characters. A common subsequence of two Strings is a
subsequence that is common to both Strings.

Constraints :
1 <= T <= 50
1 <= |STR1| <= 10^2
1 <= |STR2| <= 10^2

Where |STR1| and |STR2| denote the length of “STR1” and “STR2” respectively.

Time Limit: 1 sec

Sample Input 1 :
2
abc cadb
pqr tpuqvr
Sample Output 1 :
2
3

Explanation For Sample Input 1 :
For the first test case, the longest common subsequence is “ab” and its length
is 2.

For the second test case, the longest common subsequence is “pqr” and its length
is 3.

 */

// Recursion
int glolcs(int index1, int index2, string &str1, string &str2) {
    if (index1 < 0 || index2 < 0) {
        return 0;
    }
    // compare both the strings character at index
    if (str1[index1] == str2[index2]) {
        // match found
        return 1 + glolcs(index1 - 1, index2 - 1, str1, str2);
    } else {
        // match not found
        return 0 + max(glolcs(index1 - 1, index2, str1, str2),
                       glolcs(index1, index2 - 1, str1, str2));
    }
}
int getLengthOfLCS(string &str1, string &str2) {
    return glolcs(str1.length() - 1, str2.length() - 1, str1, str2);
}

// Recursion + memoization
int glolcs(int index1, int index2, string &str1, string &str2,
           vector<vector<int>> &dp) {
    if (index1 < 0 || index2 < 0) {
        return 0;
    }
    if (dp[index1][index2] != -1) {
        return dp[index1][index2];
    }
    // compare both the strings character at index
    if (str1[index1] == str2[index2]) {
        // match found
        return dp[index1][index2] =
                   1 + glolcs(index1 - 1, index2 - 1, str1, str2, dp);
    } else {
        // match not found
        return dp[index1][index2] =
                   0 + max(glolcs(index1 - 1, index2, str1, str2, dp),
                           glolcs(index1, index2 - 1, str1, str2, dp));
    }
}
int getLengthOfLCS(string &str1, string &str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, -1));
    return glolcs(l1 - 1, l2 - 1, str1, str2, dp);
}

// Tabulation
int getLengthOfLCS(string &str1, string &str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, 0));

    for (int index1 = 0; index1 < l1; index1++) {
        for (int index2 = 0; index2 < l2; index2++) {
            // compare both the strings character at index
            if (str1[index1] == str2[index2]) {
                // match found
                if (index1 > 0 && index2 > 0) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = 1;
                }
            } else {
                // match not found
                int moveIndex1 = 0;
                int moveIndex2 = 0;
                if (index1 > 0) {
                    moveIndex1 = dp[index1 - 1][index2];
                }
                if (index2 > 0) {
                    moveIndex2 = dp[index1][index2 - 1];
                }
                dp[index1][index2] = 0 + max(moveIndex1, moveIndex2);
            }
        }
    }
    return dp[l1 - 1][l2 - 1];
}

// Tabulation + space optimization
int getLengthOfLCS(string &str1, string &str2) {
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int>> dp(l1, vector<int>(l2, 0));
    vector<int> prev(l2, 0);
    vector<int> curr(l2, 0);
    for (int index1 = 0; index1 < l1; index1++) {
        for (int index2 = 0; index2 < l2; index2++) {
            // compare both the strings character at index
            if (str1[index1] == str2[index2]) {
                // match found
                if (index1 > 0 && index2 > 0) {
                    curr[index2] = 1 + prev[index2 - 1];
                } else {
                    curr[index2] = 1;
                }
            } else {
                // match not found
                int moveIndex1 = 0;
                int moveIndex2 = 0;
                if (index1 > 0) {
                    moveIndex1 = prev[index2];
                }
                if (index2 > 0) {
                    moveIndex2 = curr[index2 - 1];
                }
                curr[index2] = 0 + max(moveIndex1, moveIndex2);
            }
        }
        prev = curr;
    }
    return prev[l2 - 1];
}