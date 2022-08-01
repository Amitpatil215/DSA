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

#define INT_BITS 32
int maxSubarrayXOR(vector<int> &set, int n) {
    int index = 0;

    for (int i = INT_BITS - 1; i >= 0; i--) {
        int maxInd = index;
        int maxEle = INT_MIN;
        for (int j = index; j < n; j++) {
            if ((set[j] & (1 << i)) != 0 && set[j] > maxEle)
                maxEle = set[j], maxInd = j;
        }

        if (maxEle == INT_MIN) continue;

        swap(set[index], set[maxInd]);

        maxInd = index;

        for (int j = 0; j < n; j++) {
            if (j != maxInd && (set[j] & (1 << i)) != 0)
                set[j] = set[j] ^ set[maxInd];
        }

        index++;
    }

    int res = 0;
    for (int i = 0; i < n; i++) res ^= set[i];
    return res;
}

int binomialCoefficient(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }

    int res = 1;

    for (int i = 0; i < k; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int validParentheses(int N) {
    if (N % 2 == 1) return 0;
    int k = N / 2;
    int c = binomialCoefficient(N, k);
    return c / (k + 1);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int noOfParanthesis = maxSubarrayXOR(a, n);
    noOfParanthesis *= 2;
    debug(noOfParanthesis);

    int vp = validParentheses(noOfParanthesis);
    cout << vp * k << endl;
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