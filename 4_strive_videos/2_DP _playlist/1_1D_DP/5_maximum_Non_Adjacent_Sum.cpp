/*
? Maximum sum of non-adjacent elements

venice 6

Problem Statement
You are given an array/list of ‘N’ integers.
You are supposed to return the maximum sum of the subsequence
with the constraint that no two elements are adjacent in the given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number of
elements (can be zero) from the array/list, leaving the remaining elements
in their original order.

Constraints:
1 <= T <= 500
1 <= N <= 1000
0 <= ARR[i] <= 10^5

Where 'ARR[i]' denotes the 'i-th' element in the array/list.

Time Limit: 1 sec.

Sample Input 1:
2
3
1 2 4
4
2 1 4 9
Sample Output 1:
5
11

Explanation To Sample Output 1:
In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than
'ARR[1]' which is 2 so the answer is 5.

In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]'
and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take
the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in
which no elements are adjacent in the given array/list.

* Sample Input 2:
2
5
1 2 3 5 4
9
1 2 3 1 3 5 8 1 9
Sample Output 2:
8
24

Explanation To Sample Output 2:
In test case 1, out of all the possibilities, if we take the sum of 'ARR[0]',
'ARR[2]' and 'ARR[4]', i.e. 8, it will give the maximum sum of sequence in
which no elements are adjacent in the given array/list.

In test case 2, out of all the possibilities, if we take the sum of 'ARR[0]',
'ARR[2]', 'ARR[4]', 'ARR[6]' and 'ARR[8]', i.e. 24 so, it will give the maximum
sum of sequence in which no elements are adjacent in the given array/list.
 */

///? Recursion

int mnas(int index, vector<int> &nums) {
  if (index == 0) {
    /// That means we have not chosen index 1
    /// simply consider the value of this
    return nums[0];
  }
  if (index < 0) {
    return 0;
  }
  /// pick case
  /// if we picked the element we can not pick adjancent so index-2 instead of
  /// index-1
  int picked = nums[index] + mnas(index - 2, nums);

  /// if current elment not picked we can pick an elment just before it
  int notPicked = 0 + mnas(index - 1, nums);

  return max(picked, notPicked);
}
int maximumNonAdjacentSum(vector<int> &nums) {
  return mnas(nums.size() - 1, nums);
}

///? Recursion + Memoization

int mnas(int index, vector<int> &nums, vector<int> &dp) {
  if (index == 0) {
    /// That means we have not chosen index 1
    /// simply consider the value of this
    return nums[0];
  }
  if (index < 0) {
    return 0;
  }

  if (dp[index] != -1) {
    return dp[index];
  }
  /// pick case
  /// if we picked the element we can not pick adjancent so index-2 instead of
  /// index-1 
  int picked = nums[index] + mnas(index - 2, nums, dp);

  /// if current elment not picked we can pick an elment just before it
  int notPicked = 0 + mnas(index - 1, nums, dp);

  dp[index] = max(picked, notPicked);
  return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums) {
  vector<int> dp(nums.size() + 1, -1);
  return mnas(nums.size() - 1, nums, dp);
}

//? Tabulation T=O(n) s=O(n)

#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, 0);

    dp[0] = nums[0];

    for (int i = 1; i < n; i++) {
        int picked;
        if (i - 2 >= 0)  // handling edge case if i-2 becomes -ve
            picked = nums[i] + dp[i - 2];
        else
            picked = nums[i] + 0;

        int notPicked = 0 + dp[i - 1];

        dp[i] = max(picked, notPicked);
    }
    return dp[n - 1];
}

//? Tabulation + Space Optimization

#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums) {
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int picked;
        if (i - 2 >= 0)  // handling edge case if i-2 becomes -ve
            picked = nums[i] + prev2;
        else
            picked = nums[i] + 0;

        int notPicked = 0 + prev1;

        int curr = max(picked, notPicked);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}