/*
C. Classy Numbers

https://codeforces.com/problemset/problem/1036/C

Let's call some positive integer classy if its decimal representation contains
no more than 3 non-zero digits. For example, numbers 4, 200000, 10203 are classy
and numbers 4231, 102306, 7277420000 are not.

You are given a segment [L;R]. Count the number of classy integers x such that
L≤x≤R.

Each testcase contains several segments, for each of them you are required to
solve the problem separately.

Input
The first line contains a single integer T (1≤T≤104) — the number of segments in
a testcase.

Each of the next T lines contains two integers Li and Ri (1≤Li≤Ri≤1018).

Output
Print T lines — the i-th line should contain the number of classy integers on a
segment [Li;Ri].

Example
inputCopy
4
1 1000
1024 1024
65536 65536
999999 1000001
outputCopy
1000
1
0
2

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

#define int long long int

string s = "";

// dp[pos][bounded][count]
// pos -> 10^18 has 19 digits fro safer side 20 take
// bounded -> true or false value
// count -> non zero count could be 0,1,2,3
int dp[20][2][4];

int classyNumbers(int pos, bool bounded, int count) {
    if (pos == s.length()) {
        return 1;
    }

    if (dp[pos][bounded][count] != -1) {
        return dp[pos][bounded][count];
    }

    int maxDigit = -1;
    if (bounded) {
        maxDigit = s[pos] - '0';
    } else {
        maxDigit = 9;
    }

    int ans = 0;
    for (int i = 0; i <= maxDigit; i++) {
        // increase the count of non zero digit if we have placed that digit
        int updatedCount = count + (i > 0 ? 1 : 0);
        // only add the numbers who have non zero digits less than 3
        if (updatedCount <= 3) {
            // if earlier we are not bounded then we dont need to bound further
            // as we can put any number from 0 to 9
            // but if earlier number is bounded then we can be
            // ubounded -> if we are passing digit less than strings current
            // digit
            // bounded -> if we are passing digit equal to string current have
            bool updatedBound = bounded && ((s[pos] - '0') == i);
            ans += classyNumbers(pos + 1, updatedBound, updatedCount);
        }
    }
    return dp[pos][bounded][count] = ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int l, r;
    cin >> l >> r;

    s = to_string(l - 1);
    // initially it will be bounded cause lets say first digit is 8 then
    // we can use 0 to 8 values only
    int a = classyNumbers(0, true, 0);

    memset(dp, -1, sizeof(dp));
    s = to_string(r);
    int b = classyNumbers(0, true, 0);

    cout << b - a << endl;
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
s