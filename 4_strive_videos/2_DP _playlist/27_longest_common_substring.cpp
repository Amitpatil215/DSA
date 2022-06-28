/*
Longest Common Substring

venice 27

Problem Statement
You have been given two strings 'STR1' and 'STR2'. You have to find the length
of the longest common substring. A string “s1” is a substring of another string
“s2” if “s2” contains the same characters as in “s1”, in the same order and in
continuous fashion also. For Example : If 'STR1' = “abcjklp” and 'STR2' =
“acjkp”  then the output will be 3.

Explanation: The longest common substring is “cjk” which is of length 3.

Constraints:
1 <= T <= 100
1 <= |STR1|, |STR2| <= 100

Where |STR1| and |STR2|  are the lengths of the string 'STR1' and 'STR2'
respectively.

Time limit: 1 sec

Sample Input 1:
2
abcjklp acjkp
wasdijkl wsdjkl

Sample Output 1:
3
3

Explanation For Sample Output 1:
In test case 1, the longest common substring is "cjk" of length 3.

In test case 2, the longest common substring is "jkl" of length 3.
 */

// Tabulation
int lcs(string &str1, string &str2) {
    int l1 = str1.size();
    int l2 = str2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    int maxLen = 0;
    for (int index1 = 1; index1 <= l1; index1++) {
        for (int index2 = 1; index2 <= l2; index2++) {
            if (str1[index1 - 1] == str2[index2 - 1]) {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                maxLen = max(maxLen, dp[index1][index2]);
            } else {
                dp[index1][index2] = 0;
            }
        }
    }
    return maxLen;
}

// Tabulation + Space Optimization
int lcs(string &str1, string &str2) {
    int l1 = str1.size();
    int l2 = str2.size();

    vector<int> prev(l2 + 1, 0);
    vector<int> curr(l2 + 1, 0);

    int maxLen = 0;
    for (int index1 = 1; index1 <= l1; index1++) {
        for (int index2 = 1; index2 <= l2; index2++) {
            if (str1[index1 - 1] == str2[index2 - 1]) {
                curr[index2] = 1 + prev[index2 - 1];
                maxLen = max(maxLen, curr[index2]);
            } else {
                curr[index2] = 0;
            }
        }
        prev = curr;
    }
    return maxLen;
}