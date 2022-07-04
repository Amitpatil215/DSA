/*
Longest Bitonic Sequence

venice 42

Problem Statement
You are given an array/list 'ARR' consisting of 'N' positive integers. A
subsequence of 'ARR' is called bitonic if it is first increasing and then
decreasing.

For Example: An example of a bitonic sequence will be 1 < 2 < 3 < 4
> 2 > 1. Your task is to return the length of the longest bitonic sequence of
'ARR'. A subsequence of an array is an ordered subset of the array's elements
having the same sequential ordering as the original array. For Example: Let ARR
= [1, 2, 1, 2, 1]

One of the bitonic subsequences for this array will be [1, 2, 2, 1]

Constraints:
1 <= T <= 5
1 <= N <= 10^3
1 <= ARR[i] <= 10^5

Time Limit: 1sec

Sample Input 1 :
2
5
1 2 1 2 1
5
1 2 1 3 4
Sample Output 1:
4
4
Explanation For Sample Input 1:
The longest bitonic sequence for the first test case will be [1, 2, 2, 1].
The longest bitonic sequence for the second test case will be [1, 2, 3, 4].

Sample Input 2 :
2
5
1 2 3 4 5
6
12 11 40 5 3 1
Sample Output 2 :
5
5
Explanation For Sample Input 2:
The longest bitonic sequence for the first test case will be [1, 2, 3, 4, 5].
The longest bitonic sequence for the second test case will be [12, 40, 5, 3, 1].
*/

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n, 1);  // forward increasing subsequence
    for (int index = 0; index < n; index++) {
        for (int earlierIndex = 0; earlierIndex <= index - 1; earlierIndex++) {
            if (arr[index] > arr[earlierIndex]) {
                dp1[index] = max(1 + dp1[earlierIndex], dp1[index]);
            }
        }
    }
    vector<int> dp2(n, 1);  // backward increasing subsequence
    for (int index = n - 1; index >= 0; index--) {
        for (int earlierIndex = n - 1; earlierIndex >= index + 1;
             earlierIndex--) {
            if (arr[index] > arr[earlierIndex]) {
                dp2[index] = max(1 + dp2[earlierIndex], dp2[index]);
            }
        }
    }
    // find max length fro bitonic
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        int len = dp1[i] + dp2[i] - 1;
        maxLength = max(maxLength, len);
    }
    return maxLength;
}
