/* 

Input
[5,4,11,1,16,8]
[10,9,2,5,3,7,101,18]
[0,1,0,3,2,3]
[7,7,7,7,7,7,7]

Output
11 16 
2 5 7 101 
1 2 3 
7 

Refer question form 41_longest increasing subsequence

*/
// Tabualtion way
class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> rememberPrev(n);

        int maxLength = 1;
        int maxLenIndex = 0;
        for (int index = 0; index < n; index++) {
            for (int earlierIndex = 0; earlierIndex <= index - 1;
                 earlierIndex++) {
                if (nums[earlierIndex] < nums[index]) {
                    // only update if we found a element which stores max length
                    // than our curr element
                    if (1 + dp[earlierIndex] > dp[index]) {
                        rememberPrev[index] = earlierIndex;
                        dp[index] = 1 + dp[earlierIndex];
                    }
                }
            }
            if (dp[index] > maxLength) {
                maxLength = dp[index];
                maxLenIndex = index;
            }
        }

        // printing

        vector<int> ans;
        do {
            ans.push_back(nums[maxLenIndex]);
            maxLenIndex = rememberPrev[maxLenIndex];
        } while (rememberPrev[maxLenIndex] != maxLenIndex);

        // reverse the answer in order to print in ascending order as we have
        // backtracked
        reverse(ans.begin(), ans.end());

        for (auto val : ans) {
            cout << val << " ";
        }
        cout << endl;

        return maxLength;
    }
};
