/*
Minimum Number of Deletions and Insertions

venice 29

Problem Statement
You are given 2 non-empty strings “str” and “ptr” consisting of lowercase
English alphabets only. Your task is to convert string “str” into string “ptr”.

In one operation you can do either of the following on “str”: Remove a character
from any position in “str”. Add a character to any position in “str”. You have
to find the minimum number of operations required to convert string “str” into
“ptr”. 

? For Example: 
If str = “abcd”, ptr = “anc” In one operation remove str[3],
after this operation str becomes “abc”. In the second operation remove str[1],
after this operation str becomes “ac”. In the third operation add ‘n’ in str[1],
after this operation str becomes “anc”.
Hence, the output will be 3.

Sample Input 1 :
2
abcd anc
aa aaa

Sample Output 1 :
3
1

Explanation For Sample Output 1:
For the first test case,
str = “abcd”, ptr = “anc”

In one operation remove str[3], after this operation str becomes “abc”.
In the second operation remove str[1], after this operation str becomes “ac”.
In the third operation add ‘n’ in str[1], after this operation str becomes
“anc”.

Hence, the output will be 3.

For the second test case,
str = “aaa”, ptr = “aa”

In one operation remove str[2], after this operation str becomes “aa”.

Hence, the output will be 1
 */

// Tabulation
int canYouMake(string &str, string &ptr) {
    // find longest common subsequence and subtract it from the length of string
    int len1 = str.size();
    int len2 = ptr.size();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int index1 = 1; index1 <= len1; index1++) {
        for (int index2 = 1; index2 <= len2; index2++) {
            if (str[index1 - 1] == ptr[index2 - 1]) {
                dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
            } else {
                dp[index1][index2] =
                    0 + max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
            }
        }
    }

    int len_of_lcs = dp[len1][len2];
    int to_be_deleted = str.size() - len_of_lcs;
    int to_be_inserted = ptr.size() - len_of_lcs;
    return abs(to_be_deleted) + abs(to_be_inserted);
}