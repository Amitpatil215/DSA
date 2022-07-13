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

int mc(long long int index, long long int badKeys, long long int n,
       long long int k, vector<long long int> &arr,
       vector<vector<long long int>> &dp) {
    // base case
    if (index == n || badKeys > 30) {
        return 0;
    }

    if (dp[index][badKeys] != -1) {
        return dp[index][badKeys];
    }
    // recursive case
    long long int coinsToPic = arr[index] / pow(2, badKeys);
    long long int goodKeyChosen =
        (coinsToPic - k) + mc(index + 1, badKeys, n, k, arr, dp);

    badKeys += 1;
    coinsToPic = arr[index] / pow(2, badKeys);
    // coinsToPic /= 2;

    long long int badKeyChosen =
        coinsToPic + mc(index + 1, badKeys, n, k, arr, dp);
    badKeys -= 1;
    return dp[index][badKeys] = max(goodKeyChosen, badKeyChosen);
}
void solve() {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> arr;
    for (long long int i = 0; i < n; i++) {
        long long int a;
        cin >> a;
        arr.push_back(a);
    }
    vector<vector<long long int>> dp(n + 1, vector<long long int>(n + 1, -1));
    cout << mc(0, 0, n, k, arr, dp) << endl;
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