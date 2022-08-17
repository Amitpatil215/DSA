/*
Square Root Decomposition
Hard  Prev   Next
You are given a list of N numbers and Q queries.Each query is specified by two
numbers i and j.The answer to each query is the minimum number between the range
between i and j(including i and j).The query are specified using 0 based
indexing.

Expected complexity : O(Q * logN)
Input Format
The first line contains N. The next line holds N numbers. Following the list is
a number Q. The next Q lines each contain two numbers i and j which specify a
query you must answer. Output Format For each query, output the Minimum in the
range in a line. Question Video

  COMMENTConstraints
1<= N <= 10^6
1 <= Q <= 10^5
0 <= i,j <= N-1
Sample Input
4
2 4 3 1
4
1 2
1 3
2 2
0 1
Sample Output
3
1
3
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

void solve() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> q;
    vector<pair<int, int>> query;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
    }

    // length of squeare root array
    int len = ceil(sqrt(arr.size()));
    vector<int> sqrt(len, INT_MAX);

    // precompute min value for each group
    for (int i = 0; i < n; i++) {
        int sqrtIndex = i / len;
        sqrt[sqrtIndex] = min(sqrt[sqrtIndex], arr[i]);
    }

    // find min for q queries
    for (int k = 0; k < q; k++) {
        int l = query[k].first;
        int r = query[k].second;

        int minVal = INT_MAX;

        int i = l;
        while (i <= r) {
            // check if curr index is starting of the block
            // and does complete block is within range or not
            if (i % len == 0 && (i + len - 1) <= r) {
                int sqrtIndex = i / len;
                minVal = min(minVal, sqrt[sqrtIndex]);
                i += len;
            } else {
                minVal = min(minVal, arr[i]);
                i++;
            }
        }
        cout << minVal << " ";
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("E:/Work/Interview Prep/DSA/playground/input.txt", "r", stdin);
    freopen("E:/Work/Interview Prep/DSA/playground/output.txt", "w", stdout);
#endif
    clock_t z = clock();
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}