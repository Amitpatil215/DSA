/*
1312. Minimum Insertion Steps to Make a String Palindrome

venice 28

Given a string s. In one step you can insert any character at any index of the
string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we don't need any
insertions. 

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.

 */
// Tabulation
class Solution {
   public:
    int lps(string &s1, string &s2) {
        int len = s1.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));

        for (int index1 = 1; index1 <= len; index1++) {
            for (int index2 = 1; index2 <= len; index2++) {
                if (s1[index1 - 1] == s2[index2 - 1]) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] =
                        0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }
        return dp[len][len];
    }

    int minInsertions(string s) {
        string str1 = s;
        string str2 = s;
        reverse(str2.begin(), str2.end());

        // find length of longest palindromic subsequence
        int len_of_lps = lps(str1, str2);
        return s.size() - len_of_lps;
    }
};