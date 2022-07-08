// House Robber II
// venice 7

/*
Mr. X is a professional robber planning to rob houses along a street. Each house
has a certain amount of money hidden. All houses along this street are arranged
in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected, and it will
automatically contact the police if two adjacent houses were broken into on the
same night. You are given an array/list of non-negative integers 'ARR'
representing the amount of money of each house. Your task is to return the
maximum amount of money Mr. X can rob tonight without alerting the police.

Sample Input 1:
3
1
0
3
2 3 2
4
1 3 2 1
Sample Output 1:
0
3
4
Explanation Of Input 1:
(i) Mr. X has only one house to rob, but with no money.

(ii) Mr. X cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent houses (remember, it’s a circular street). So, he’ll
rob only house 2 (money = 3) with a maximum value

(iii) Mr. X will get maximum value when he robs house 2 (money = 3) and then
robs house 4 (money = 1) i.e. 4 units of money.
 */

//? Logic
/// USing maximum non adjancent sum questions logic
// we just need to apply same code 2 times first time including 1st element and
// 2nd time including last element and then take maximum of them.

//? Space optimized tabulation

#include <bits/stdc++.h>

long long int hr(vector<int>& nums) {
    int n = nums.size();

    long long int prev1 = nums[0];

    long long int prev2 = 0;

    for (int i = 1; i < n; i++) {
        long long int robbedCurr;
        if (i - 2 >= 0)  // handling edge case if i-2 becomes -ve
            robbedCurr = nums[i] + prev2;
        else
            robbedCurr = nums[i] + 0;

        long long int notRobbedCurr = 0 + prev1;

        long long int curr = max(robbedCurr, notRobbedCurr);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse) {
    vector<int> temp1, temp2;
    int n = valueInHouse.size();
    if (n == 1) {
        return hr(valueInHouse);
    }
    /// generating two vectors one with excluding first and one with excluding
    /// last element
    for (int i = 0; i < n; i++) {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    return max(hr(temp1), hr(temp2));
}