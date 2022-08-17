/*

https://www.codingninjas.com/codestudio/library/book-allocation-problem
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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = arr[0];
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int high = sum;
    int ans = INT_MAX;
    while (low < high) {
        // debug(low, high);
        int mid = low + (high - low) / 2;
        // int currIndex = 0;
        int noOfGroupsAssigned = m;
        int currIndex = 0;
        while (noOfGroupsAssigned != 0) {
            int currSum = 0;
            int maxSum = INT_MIN;
            for (currIndex = 0; currIndex < n; currIndex++) {
                // debug(currIndex);
                currSum += arr[currIndex];
                // debug(currSum);
                if (currSum <= mid && currIndex == n - 1) {
                    noOfGroupsAssigned--;
                    // debug(noOfGroupsAssigned);
                }
                if (currSum > mid) {
                    maxSum = max(maxSum, currSum - arr[currIndex]);
                    currSum = 0;
                    // debug(currSum);
                    currIndex--;
                    noOfGroupsAssigned--;
                    // debug(noOfGroupsAssigned);
                    if (noOfGroupsAssigned == 0) break;
                }
            }
        }
        // debug(noOfGroupsAssigned, currIndex);
        if (noOfGroupsAssigned > 0 || currIndex <= m) {
            low = mid + 1;
            // cout << "set low as" << mid + 1 << endl;
        } else {
            high = mid;
            ans = min(ans, mid);
            // cout << "set high as" << mid << endl;
        }
        // debug(low, high);
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