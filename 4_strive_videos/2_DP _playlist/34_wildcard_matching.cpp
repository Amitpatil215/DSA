
/*
 */
// Recursion
// Note: following 1 based indexing
bool wm(int index1, int index2, string &pattern, string &str) {
    if (index1 == 0 && index2 == 0) {
        return true;
    }
    if (index1 > 0 && index2 == 0) {
        for (int i = 0; i < index1; i++) {
            if (pattern[i] != '*') {
                return false;
            }
        }
        return true;
    }
    if (index1 == 0 && index2 > 0) {
        return false;
    }

    // recursive case
    if (pattern[index1 - 1] == str[index2 - 1] || pattern[index1 - 1] == '?') {
        return wm(index1 - 1, index2 - 1, pattern, str);
    } else if (pattern[index1 - 1] == '*') {
        return wm(index1 - 1, index2, pattern, str) ||
               wm(index1, index2 - 1, pattern, str);
    } else {
        // we did not found any matach
        return false;
    }
}

bool wildcardMatching(string pattern, string text) {
    int l1 = pattern.size();
    int l2 = text.size();
    return wm(l1, l2, pattern, text);
}

// Memoization
#include <bits/stdc++.h>
// following 1 based indexing
bool wm(int index1, int index2, string &pattern, string &str,
        vector<vector<int>> &dp) {
    if (index1 == 0 && index2 == 0) {
        return true;
    }
    if (index1 > 0 && index2 == 0) {
        for (int i = 0; i < index1; i++) {
            if (pattern[i] != '*') {
                return false;
            }
        }
        return true;
    }
    if (index1 == 0 && index2 > 0) {
        return false;
    }

    if (dp[index1][index2] != -1) {
        return dp[index1][index2];
    }
    // recursive case
    if (pattern[index1 - 1] == str[index2 - 1] || pattern[index1 - 1] == '?') {
        return dp[index1][index2] =
                   wm(index1 - 1, index2 - 1, pattern, str, dp);
    } else if (pattern[index1 - 1] == '*') {
        return dp[index1][index2] = wm(index1 - 1, index2, pattern, str, dp) ||
                                    wm(index1, index2 - 1, pattern, str, dp);
    } else {
        // we did not found any matach
        return dp[index1][index2] = false;
    }
}

bool wildcardMatching(string pattern, string text) {
    int l1 = pattern.size();
    int l2 = text.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
    return wm(l1, l2, pattern, text, dp);
}

// Tabulation
#include <bits/stdc++.h>
bool wildcardMatching(string pattern, string text) {
    int l1 = pattern.size();
    int l2 = text.size();
    string str =
        text;  // as we have used str instead of text in Memoization solution
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));

    for (int index1 = 0; index1 <= l1; index1++) {
        for (int index2 = 0; index2 <= l2; index2++) {
            // base case here
            if (index1 == 0 && index2 == 0) {
                dp[index1][index2] = true;
            } else if (index1 > 0 && index2 == 0) {
                bool isEveryCharIsAstrik = true;
                for (int i = 0; i < index1; i++) {
                    if (pattern[i] != '*') {
                        isEveryCharIsAstrik = false;
                        break;
                    }
                }
                dp[index1][index2] = isEveryCharIsAstrik;
            } else if (index1 == 0 && index2 > 0) {
                dp[index1][index2] = false;
            } else {
                // recursive case here
                if (pattern[index1 - 1] == str[index2 - 1] ||
                    pattern[index1 - 1] == '?') {
                    dp[index1][index2] = dp[index1 - 1][index2 - 1];
                } else if (pattern[index1 - 1] == '*') {
                    dp[index1][index2] =
                        dp[index1 - 1][index2] || dp[index1][index2 - 1];
                } else {
                    // we did not found any matach
                    dp[index1][index2] = false;
                }
            }
        }
    }
    return dp[l1][l2];
}