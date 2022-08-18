/*

Longest Sub-Array with Sum K


https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

Given an array containing N integers and an integer K., Your task is to find the
length of the longest Sub-Array with the sum of the elements equal to the given
value K.

Example 1:

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input :
A[] = {-1, 2, 3}
K = 6
Output : 0
Explanation:
There is no such sub-array with sum 6.
Your Task:
This is a function problem. The input is already taken care of by the driver
code. You only need to complete the function smallestSubsegment() that takes an
array (A), sizeOfArray (n),  sum (K)and returns the required length of the
longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).



Constraints:
1<=N<=105
-105<=A[i], K<=105
 */

class Solution {
   public:
    int lenOfLongSubarr(int arr[], int N, int k) {
        int sum = 0;
        int maxLen = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
            int diff = sum - k;
            // check wheter difference present in map
            // if present calculate length of the subarray
            //  if not present then input the sum
            if (m.find(diff) != m.end()) {
                int indexFromMap = m[diff];
                maxLen = max(maxLen, i - indexFromMap);
            }
            if (m.find(sum) == m.end()) {
                m[sum] = i;
            }
        }
        return maxLen;
    }
};
