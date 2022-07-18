/*
Venice 29

Shortest Common Supersequence

Problem Statement
Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’,
containing both ‘A’ and ‘B’ as its subsequences. If there are multiple answers,
return any of them. Note: A string 's' is a subsequence of string 't' if
deleting some number of characters from 't' (possibly 0) results in the string
's'. For Example: Suppose ‘A’ = “brute”, and ‘B’ = “groot”

The shortest supersequence will be “bgruoote”. As shown below, it contains both
‘A’ and ‘B’ as subsequences.

A   A A     A A
b g r u o o t e
  B B   B B B

It can be proved that the length of supersequence for this input cannot be less
than 8. So the output will be bgruoote.

Constraints:
1 ≤ T ≤ 100
1 ≤ |A|, |B| ≤ 1000
Both strings consist of only lowercase English letters.
1 ≤ Σ(|A|+|B|) ≤ 3000

Time limit: 1 Sec

Sample Input 1 :
2
brute
groot
bleed
blue

Sample Output 1 :
bgruoote
bleued
*/

//  Tabulation
#include <bits/stdc++.h>
string shortestSupersequence(string str1, string str2) {
    // generate LCS DP
    int l1 = str1.size();
    int l2 = str2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int index1 = 1; index1 <= l1; index1++) {
        for (int index2 = 1; index2 <= l2; index2++) {
            if (str1[index1 - 1] == str2[index2 - 1]) {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } else {
                dp[index1][index2] =
                    0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    // Printing the shortest common supersequence using DP matrix
    string ans = "";
    int index1 = l1;
    int index2 = l2;

    // iterate till one one of the string ends
    while (index1 > 0 && index2 > 0) {
        if (str1[index1 - 1] == str2[index2 - 1]) {
            // only include once in the ans string
            ans += str1[index1 - 1];
            // move digonally up
            index1--;
            index2--;
        } else {
            if (dp[index1 - 1][index2] > dp[index1][index2 - 1]) {
                // consider the one which we are ommiting
                ans += str1[index1 - 1];
                index1--;
            } else {
                ans += str2[index2 - 1];
                index2--;
            }
        }
    }

    // we are left with any one of the string more
    // then we have to append it
    while (index1 > 0) {
        ans += str1[index1 - 1];
        index1--;
    }

    while (index2 > 0) {
        ans += str2[index2 - 1];
        index2--;
    }

    // we have iterated from back so need to reverse our answer string
    reverse(ans.begin(), ans.end());
    return ans;
}