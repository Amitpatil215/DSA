/*
2376. Count Special Integers

https://leetcode.com/contest/weekly-contest-306/problems/count-special-integers/

Editorial
https://leetcode.com/problems/count-special-integers/discuss/2422090/C%2B%2B-with-explanation-Digit-Dynamic-Programming

We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to
the interval [1, n].

Example 1:

Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there
are 19 special integers. Example 2:

Input: n = 5
Output: 5
Explanation: All the integers from 1 to 5 are special.
Example 3:

Input: n = 135
Output: 110
Explanation: There are 110 integers from 1 to 135 that are special.
Some of the integers that are not special are: 22, 114, and 131.


Constraints:

1 <= n <= 2 * 109
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

string s = "";

// dp[pos][bounded][mask]
// pos -> 10^9 has 11 digits for safer side 11 take
// bounded -> true or false value
// mask -> using mask as a state for storing which digits are used
// for 8 we will set 7th bit of the mask
int dp[11][2][1024];

int specialIntegers(int pos, bool bounded, int mask) {
    if (pos == s.length()) {
        return mask != 0;
    }

    if (dp[pos][bounded][mask] != -1) {
        return dp[pos][bounded][mask];
    }

    int maxDigit = -1;
    if (bounded) {
        maxDigit = s[pos] - '0';
    } else {
        maxDigit = 9;
    }

    int ans = 0;
    for (int i = 0; i <= maxDigit; i++) {
        // check whether current digit is used before or not
        // by checking its set bit
        bool isAlreadyUsed = mask & (1 << i);
        // only add the numbers who have non zero digits less than 3
        if (!isAlreadyUsed) {
            // if earlier we are not bounded then we dont need to bound further
            // as we can put any number from 0 to 9
            // but if earlier number is bounded then we can be
            // ubounded -> if we are passing digit less than strings current
            // digit
            // bounded -> if we are passing digit equal to string current have
            bool updatedBound = bounded && ((s[pos] - '0') == i);
            // setting ith bit to indicate that that digit is used
            int updatedmask = (mask == 0 && i == 0) ? mask : mask | (1 << i);
            ans += specialIntegers(pos + 1, updatedBound, updatedmask);
        }
    }
    return dp[pos][bounded][mask] = ans;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    s = to_string(n);
    // initially it will be bounded cause lets say first digit is 8 then
    // we can use 0 to 8 values only
    int a = specialIntegers(0, true, 0);

    cout << a << endl;
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