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
const int m = 1e9 + 7;

int numPermsDISequence(string S) {
    int n = S.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int j = 0; j <= n; j++) dp[0][j] = 1;
    for (int i = 0; i < n; i++) {
        if (S[i] == '+') {
            for (int j = 0, curr = 0; j < n - i; j++) {
                curr = (dp[i][j] + curr) % m;
                dp[i + 1][j] = (dp[i + 1][j] + curr) % m;
            }
        } else {
            for (int j = n - i - 1, curr = 0; j >= 0; j--) {
                curr = (dp[i][j + 1] + curr) % m;
                dp[i + 1][j] = (dp[i + 1][j] + curr) % m;
            }
        }
    }
    return dp[n][0];
}
void solve() {
    cout<<numPermsDISequence("-+-")<<endl;
    cout<<numPermsDISequence("-")<<endl;
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