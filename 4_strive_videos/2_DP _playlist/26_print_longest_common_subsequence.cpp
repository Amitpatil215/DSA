/* 
Print longest common subsequence

venice 26

 */
#include <bits/stdc++.h>
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
    // printing DP Matrix
    for (int index1 = 0; index1 < l1; index1++) {
        for (int index2 = 0; index2 < l2; index2++) {
            cout << dp[index1][index2] << " ";
        }
        cout << endl;
    }

    // Printing LCS String
    int startIndex1 = l1 - 1;
    int startIndex2 = l2 - 1;
    string s = "";
    while (startIndex1 >= 0 && startIndex2 >= 0) {
        if (str1[startIndex1] == str2[startIndex2]) {
            s += str1[startIndex1];
            startIndex1--;
            startIndex2--;
        } else {
            // get max of both and move to that index
            //  we shouldn't consider if startIndex-1 <0 or startIndex2-1 <0
            //  instead we whould mark its value as 0  so that it couldn't be
            //  considered in the ans
            int prevRowCurrCol =
                startIndex1 - 1 >= 0 ? dp[startIndex1 - 1][startIndex2] : 0;
            int currRowPrevCol =
                startIndex2 - 1 >= 0 ? dp[startIndex1][startIndex2 - 1] : 0;

            if (prevRowCurrCol > currRowPrevCol) {
                startIndex1--;
            } else {
                startIndex2--;
            }
        }
    }
    // as we iterated from back we need to reverse the ans string to make it
    // ordered.
    reverse(s.begin(), s.end());
    cout << s << endl;

    // returing length of the longest common subsequence
    return dp[l1 - 1][l2 - 1];
}