/*
AGGRCOW - Aggressive cows
https://www.spoj.com/problems/AGGRCOW/

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The
stalls are located along a straight line at positions x1,...,xN (0 <= xi <=
1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive
towards each other once put into a stall. To prevent the cows from hurting each
other, FJ wants to assign the cows to the stalls, such that the minimum distance
between any two of them is as large as possible. What is the largest minimum
distance? Input t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
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

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[n - 1] - arr[0];

    int ans = 1;
    int dist = -1;
    // apply binary seach
    while (low <= high) {
        int noOfCows = c;
        int mid = (low + high) / 2;

        int lastAllotedCow = 0;
        noOfCows--;
        int currIndex = 1;
        while (noOfCows != 0 && currIndex < n) {
            dist = abs(arr[currIndex] - arr[lastAllotedCow]);

            if (dist >= mid) {
                lastAllotedCow = currIndex;

                noOfCows--;
            }
            currIndex++;
        }
        if (noOfCows == 0) {
            low = mid + 1;
            ans = max(mid, ans);
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
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