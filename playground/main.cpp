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
int maxSum(int index, int position, vector<int> &arr, vector<vector<int>> &dp) {
    if (index >= arr.size()) {
        return 0;
    }
    if (dp[index][position] != -1) {
        return dp[index][position];
    }
    int pick = position * arr[index] + maxSum(index + 1, position + 1, arr, dp);
    int notPick = 0 + maxSum(index + 1, position, arr, dp);
    return dp[index][position] = max(pick, notPick);
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // cout << maxSum(0, 1, arr, dp) << endl;

    for (int index = n - 1; index >= 0; index--) {
        for (int position = index; position >= 1; position--) {
            int pick = position * arr[index] + dp[index + 1][position + 1];
            //    maxSum(index + 1, position + 1, arr, dp);
            int notPick = 0 + dp[index + 1][position];
            dp[index][position] = max(pick, notPick);
        }
    }
    cout << dp[0][1] << endl;
}

int main() {
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