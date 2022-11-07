/*

https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/arrays-and-strings/k-sum-target-sum-unique-set/ojquestion

K Sum - Target Sum Unique Set
Hard  Prev   Next
1. Given an array nums of 'n' integers and a variable 'K'.
2. You have to return an array of all the unique set [nums[a], nums[b], nums[c],
nums[d] . . . K Elements] such that: 2.1 a, b, c, d . . . K Elements are less
than 'n' and greater than 0. 2.2 a,. b, c, d upto K different indexes are
Unique. 2.3 nums[a] + nums[b] + nums[c] + nums[d] + . . . + nums[K distinct
indexes] == target.
3. You can return answer in any order.
Input Format
Input is managed for you.
Output Format
Output is managed for you.
Question Video

  COMMENTConstraints
1. 1 <= nums.length <= 200
2. -10^9 <= nums[i] <= 10^9
3. -10^9 <= target <= 10^9
4. 1 <= K <= nums.length
Sample Input
6
-1 0 1 2 -1 -4
0
3
Sample Output
-1 -1 2
-1 0 1
 */
#include <bits/stdc++.h>
using namespace std;

#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#define int long
vector<vector<int>> twoSum(vector<int> &nums, long target, int si) {
    // asuming that nums is sorted alredy
    vector<vector<int>> ans;
    int left = si, right = nums.size() - 1;
    while (left < right) {
        // if duplicate found then skip
        if (left != si && nums[left] == nums[left - 1]) {
            left++;
            continue;
        }
        long sum = nums[left] + nums[right];
        if (target == sum) {
            vector<int> subAns(2);
            subAns[0] = nums[left];
            subAns[1] = nums[right];

            ans.push_back(subAns);
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return ans;
}
vector<vector<int>> kSum(int n, vector<int> &nums, int target, int k, int si) {
    vector<vector<int>> ans;
    if (k == 2) {
        auto x = twoSum(nums, target, si);

        return x;
    }
    for (int i = si; i < n - k; i++) {
        if (i != si && nums[i] == nums[i - 1]) continue;
        vector<vector<int>> subAns =
            kSum(n, nums, target - nums[i], k - 1, i + 1);
        for (auto &vec : subAns) {
            vec.push_back(nums[i]);
            ans.push_back(vec);
        }
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int target, k;
    cin >> target >> k;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans = kSum(n, nums, target, k, 0);
    for (auto veco : ans) {
        for (auto veci : veco) {
            cout << veci << " ";
        }
        cout << endl;
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("E:/Work/Interview Prep/DSA/playground/input.txt", "r", stdin);
    freopen("E:/Work/Interview Prep/DSA/playground/output.txt", "w", stdout);
#endif
    clock_t z = clock();
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}