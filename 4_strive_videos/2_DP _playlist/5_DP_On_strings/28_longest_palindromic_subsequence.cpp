/*
Longest Palindromic Subsequence

venice 28

Problem Statement
You have been given a string ‘A’ consisting of lower case English letters. Your
task is to find the length of the longest palindromic subsequence in ‘A’. A
subsequence is a sequence generated from a string after deleting some or no
characters of the string without changing the order of the remaining string
characters. (i.e. “ace” is a subsequence of “abcde” while “aec” is not). A
string is said to be palindrome if the reverse of the string is the same as the
actual string. For example, “abba” is a palindrome, but “abbc” is not a
palindrome.

Constraints:
1 <= T <= 10
1 <= N <= 10 ^ 2

Where ‘T’ is the number of test cases, and ‘N’ is the length of the string.

Time limit: 1 sec.

Sample Input 1:
2
bbabcbcab
bbbab

Sample Output 1:
7
4

Explanation Of Sample Input 1:
For the first test case, the longest palindromic subsequence is “babcbab”, which
has a length of 7. “bbbbb” and “bbcbb” are also palindromic subsequences of the
given string, but not the longest one.

For the second test case, the longest palindromic subsequence is “bbbb”, which
has a length of 4.

*/

// Tabulation
#include <bits/stdc++.h>

int longestPalindromeSubsequence(string s) {
    // build LCS using Tabulation
    string str1 = s;
    string str2 = s;
    reverse(str2.begin(), str2.end());

    int len = str1.length();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

    for (int index1 = 1; index1 <= len; index1++) {
        for (int index2 = 1; index2 <= len; index2++) {
            // string indexing starts with 0 so we have to handle it by
            // subtracting 1 from index
            if (str1[index1 - 1] == str2[index2 - 1]) {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } else {
                dp[index1][index2] =
                    0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }
    return dp[len][len];
}