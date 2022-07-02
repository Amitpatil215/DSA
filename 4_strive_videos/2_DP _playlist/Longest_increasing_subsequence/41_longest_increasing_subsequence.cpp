// Recursion
/*
300. Longest Increasing Subsequence

vencie 38
Given an integer array nums, return the length of the longest strictly
increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some
or no elements without changing the order of the remaining elements. For
example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4. Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1


Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Follow up: Can you come up with an algorithm that runs in O(n log(n)) time
complexity?

 */

class Solution {
   public:
    int lOLIS(int index, int earlierIndex, vector<int>& nums, int& n) {
        if (index == n) {
            return 0;
        }

        if (earlierIndex == -1 || nums[index] > nums[earlierIndex]) {
            int take = 1 + lOLIS(index + 1, index, nums, n);
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n);
            return max(take, doNotTake);
        } else {
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n);
            return doNotTake;
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lOLIS(0, -1, nums, n);
    }
};

//  Recursion + memoization
class Solution {
   public:
    int lOLIS(int index, int earlierIndex, vector<int>& nums, int& n,
              vector<vector<int>>& dp) {
        if (index == n) {
            return 0;
        }
        if (dp[index][earlierIndex + 1] != -1) {
            return dp[index][earlierIndex + 1];
        }

        if (earlierIndex == -1 || nums[index] > nums[earlierIndex]) {
            int take = 1 + lOLIS(index + 1, index, nums, n, dp);
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n, dp);
            return dp[index][earlierIndex + 1] = max(take, doNotTake);
        } else {
            int doNotTake = 0 + lOLIS(index + 1, earlierIndex, nums, n, dp);
            return dp[index][earlierIndex + 1] = doNotTake;
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lOLIS(0, -1, nums, n, dp);
    }
};

// Tabulation
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int index = n; index >= 0; index--) {
            // earlier index will definitely be lying from -1 to index-1 so
            for (int earlierIndex = index - 1; earlierIndex >= -1;
                 earlierIndex--) {
                if (index == n) {
                    dp[index][earlierIndex + 1] = 0;
                } else {
                    if (earlierIndex == -1 ||
                        nums[index] > nums[earlierIndex]) {
                        int take = 1 + dp[index + 1][index + 1];
                        int doNotTake = 0 + dp[index + 1][earlierIndex + 1];
                        dp[index][earlierIndex + 1] = max(take, doNotTake);
                    } else {
                        int doNotTake = 0 + dp[index + 1][earlierIndex + 1];
                        dp[index][earlierIndex + 1] = doNotTake;
                    }
                }
            }
        }
        return dp[0][0];
    }
};

// Tabulation + space optimization
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int index = n; index >= 0; index--) {
            // earlier index will definitely be lying from -1 to index-1 so
            for (int earlierIndex = index - 1; earlierIndex >= -1;
                 earlierIndex--) {
                if (index == n) {
                    prev[earlierIndex + 1] = 0;
                } else {
                    if (earlierIndex == -1 ||
                        nums[index] > nums[earlierIndex]) {
                        int take = 1 + prev[index + 1];
                        int doNotTake = 0 + prev[earlierIndex + 1];
                        curr[earlierIndex + 1] = max(take, doNotTake);
                    } else {
                        int doNotTake = 0 + prev[earlierIndex + 1];
                        curr[earlierIndex + 1] = doNotTake;
                    }
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};

// Another way for tabulation
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxLength = 1;
        for (int index = 0; index < n; index++) {
            for (int earlierIndex = 0; earlierIndex <= index - 1;
                 earlierIndex++) {
                if (nums[earlierIndex] < nums[index]) {
                    dp[index] = max(dp[index], 1 + dp[earlierIndex]);
                }
            }
            maxLength = max(maxLength, dp[index]);
        }
        return maxLength;
    }
};
