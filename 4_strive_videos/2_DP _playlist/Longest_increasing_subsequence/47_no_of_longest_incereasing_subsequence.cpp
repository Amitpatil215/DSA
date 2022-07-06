/*
Number of Longest Increasing Subsequence

venice 42

Given an integer array ‘ARR’ of length ‘N’, return the number of longest
increasing subsequences in it. The longest increasing subsequence(LIS) is the
longest subsequence of the given sequence such that all elements of the
subsequence are in increasing order. Note : The subsequence should be a strictly
increasing sequence.

For Example : Let ‘ARR’ = [50, 3, 90, 60, 80]. In this
array the longest increasing subsequences are [50, 60, 80] and [3, 60, 80].
There are other increasing subsequences as well but we need the number of
longest ones. Hence the answer is 2.
s
Constraints :
1 ≤ T ≤ 10
1 ≤ N ≤ 2000
1 ≤ ARR[i] ≤ 10 ^ 6
Time limit: 1 sec

Sample Input 1 :
2
5
50 3 90 60 80
4
3 7 4 6
Sample Output 1 :
2
1

Explanation For Sample Input 1 :
For test case 1 :
The length of LIS is 3 and there are two such LIS, which are[50, 60, 80] and [3,
60, 80].

For test case 2 :
The length of LIS is 3 and there is only one such LIS, which is [3, 4, 6].
Sample Input 2 :
2
4
5 7 2 3
3
4 4 4
Sample Output 2 :
2
3

Explanation For Sample Input 2 :
For test case 1 :
The length of LIS is 2 and there are two such LIS, which are [5, 7] and [2, 3].

For test case 2 :
The length of LIS is 1 and there are three such LIS, which are [4], [4], [4].
*/

int findNumberOfLIS(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);

    int maxLength = 0;
    for (int index = 0; index < n; index++) {
        for (int earlierIndex = 0; earlierIndex <= index - 1; earlierIndex++) {
            if (arr[index] > arr[earlierIndex]) {
                if (1 + dp[earlierIndex] > dp[index]) {
                    dp[index] = 1 + dp[earlierIndex];
                    count[index] = count[earlierIndex];
                } else if (1 + dp[earlierIndex] == dp[index]) {
                    count[index] += count[earlierIndex];
                }
            }
        }
        maxLength = max(maxLength, dp[index]);
    }
    // find all the subsequences with max length and add their repsective counts
    // to get total no of subsequences with longest increasing subsequence
    int no = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLength) {
            no += count[i];
        }
    }
    return no;
}