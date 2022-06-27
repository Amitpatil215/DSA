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

void solve() {
    long long int n;
    cin >> n;
    vector<int> arr;
    while (n > 0) {
        int x = n % 10;
        n = n / 10;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    vector<int> num1;
    vector<int> num2;
    int si = 0;
    int ei = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            num1.push_back(arr[i]);
        } else
            num2.push_back(arr[i]);
    }
    long long sum1 = 0;
    long long sum2 = 0;
    long long factor = 1;

    for (int i = num1.size() - 1; i >= 0; i--) {
        sum1 += num1[i] * factor;
        factor *= 10;
    }
    factor = 1;
    for (int i = num2.size() - 1; i >= 0; i--) {
        sum2 += num2[i] * factor;
        factor *= 10;
    }
    // debug(sum1, sum2);
    long long int sum = 0;
    sum = sum1 + sum2;
    cout << sum << endl;
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