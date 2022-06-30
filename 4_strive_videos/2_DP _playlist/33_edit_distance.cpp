// recursion
class Solution {
   public:
    int md(int index1, int index2, string &word1, string &word2) {
        // base case
        if (index1 < 0) {
            return index2 + 1;
        }

        if (index2 < 0) {
            return index1 + 1;
        }

        // recursive case
        if (word1[index1] == word2[index2]) {
            // found a match
            return 0 + md(index1 - 1, index2 - 1, word1, word2);
        } else {
            int deleteOperation = md(index1 - 1, index2, word1, word2);
            int insertOperation = md(index1, index2 - 1, word1, word2);
            int replaceOperation = md(index1 - 1, index2 - 1, word1, word2);
            return 1 +
                   min(deleteOperation, min(insertOperation, replaceOperation));
        }
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        return md(len1 - 1, len2 - 1, word1, word2);
    }
};

// recursion + memoization
class Solution {
   public:
    int md(int index1, int index2, string &word1, string &word2,
           vector<vector<int>> &dp) {
        // base case
        if (index1 < 0) {
            return index2 + 1;
        }

        if (index2 < 0) {
            return index1 + 1;
        }

        if (dp[index1][index2] != -1) {
            return dp[index1][index2];
        }

        // recursive case
        if (word1[index1] == word2[index2]) {
            // found a match
            return dp[index1][index2] =
                       0 + md(index1 - 1, index2 - 1, word1, word2, dp);
        } else {
            int deleteOperation = md(index1 - 1, index2, word1, word2, dp);
            int insertOperation = md(index1, index2 - 1, word1, word2, dp);
            int replaceOperation = md(index1 - 1, index2 - 1, word1, word2, dp);
            return dp[index1][index2] =
                       1 + min(deleteOperation,
                               min(insertOperation, replaceOperation));
        }
    }
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        return md(len1 - 1, len2 - 1, word1, word2, dp);
    }
};

// Tabulation
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        // base case
        for (int index2 = 0; index2 <= len2; index2++) {
            dp[0][index2] = index2;
        }

        for (int index1 = 0; index1 <= len1; index1++) {
            dp[index1][0] = index1;
        }

        for (int index1 = 1; index1 <= len1; index1++) {
            for (int index2 = 1; index2 <= len2; index2++) {
                if (word1[index1 - 1] == word2[index2 - 1]) {
                    // found a match
                    dp[index1][index2] = 0 + dp[index1 - 1][index2 - 1];
                } else {
                    int deleteOperation = dp[index1 - 1][index2];
                    int insertOperation = dp[index1][index2 - 1];
                    int replaceOperation = dp[index1 - 1][index2 - 1];
                    dp[index1][index2] =
                        1 + min(deleteOperation,
                                min(insertOperation, replaceOperation));
                }
            }
        }
        return dp[len1][len2];
    }
};

// Tabulation + space  optimization
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();

        vector<int> prev(len2 + 1, 0);
        vector<int> curr(len2 + 1, 0);

        // base case

        for (int index2 = 0; index2 <= len2; index2++) {
            prev[index2] = index2;  // dp[0] will be our prev row as we are
                                    // following 1 based indexing
        }

        // we will not rquire this anymore as we relying on only two rows prev
        // and curr so no need to assign other values like dp[2][0]=2,
        // dp[3][0]=3...so on
        //* but we need to make sure that every curr[0]=index1 ..see for loop
        /* for(int index1=0;index1<=len1; index1++){
            dp[index1][0] = index1;
        } */

        for (int index1 = 1; index1 <= len1; index1++) {
            curr[0] = index1;
            for (int index2 = 1; index2 <= len2; index2++) {
                if (word1[index1 - 1] == word2[index2 - 1]) {
                    // found a match
                    curr[index2] = 0 + prev[index2 - 1];
                } else {
                    int deleteOperation = prev[index2];
                    int insertOperation = curr[index2 - 1];
                    int replaceOperation = prev[index2 - 1];
                    curr[index2] =
                        1 + min(deleteOperation,
                                min(insertOperation, replaceOperation));
                }
            }
            prev = curr;
        }
        return prev[len2];
    }
};