/*
Range Addition

https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/range-queries/range-addition/ojquestion
Medium  Prev   Next
1. You are given a number N.
 2. Assume you have an array of length N initialised with all 0's.
 3. You are also given K update operations.
 4. Each operation contain 3 numbers: startIndex, endIndex and inc and updates
each element of the subarray arr[startIndex, endIndex](both inclusive) with inc.
 5. You have to find the resultant array when all K operations are executed.
 6. display is a utility function, feel free to use it for debugging purposes.
 7. main takes input from the users.
 8. This is a functional problem.
 9. You have to complete the getModifiedArray function. It takes as input a
length and a 2D array of update operations. It should return the modified array.
 10. Don't change the code of main and display.

Expected Complexity : O(n+k)
Input Format
First line takes input N, the length of the array.
 Second line takes input K, the number of update operations.
 Next K lines take input 3 space separated integers representing the startIndex,
endIndex and inc. Input is handled for you. Output Format The resultant array.
 Output is handled for you.
Question Video

  COMMENTConstraints
1 <= N <= 30000
Sample Input
4
3
0 2 -1
2 2 2
1 3 1
Sample Output
-1 0 2 1

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
    int n, q, m;
    cin >> n >> q >> m;
    // generating range additon
    vector<int> arr(n + 1, 0);
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({l, r});
        arr[l] += 1;
        if (r + 1 < n + 1) arr[r + 1] += -1;
    }

    // generate prefix sum
    vector<int> rangeAddition(n + 1, 0);
    int sum = 0;

    for (int i = 0; i <= n; i++) {
        sum += arr[i];
        rangeAddition[i] = sum;
    }

    // generate prefix count
    int currm = 0, currm_plus1 = 0;
    vector<int> countm(n + 1, 0), countm_plus1(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        int val = rangeAddition[i];
        if (val == m) {
            currm++;
        } else if (val == m + 1) {
            currm_plus1++;
        }
        countm[i] = currm;
        countm_plus1[i] = currm_plus1;
    }

    // check which query will give maximum number of roses
    int maxRoses = 0;
    int totalCountWithoutExcluding = countm[n];
    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i].first;
        int r = queries[i].second;

        int loss = countm[r] - ((l != 0) ? countm[l - 1] : 0);
        int gain = countm_plus1[r] - ((l != 0) ? countm_plus1[l - 1] : 0);

        // total roses left after removing query i
        int totalLeft = totalCountWithoutExcluding - loss + gain;
        maxRoses = max(maxRoses, totalLeft);
    }
    cout << maxRoses;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("E:/Work/Interview Prep/DSA/playground/input.txt", "r",
    //     stdin); freopen("E:/Work/Interview Prep/DSA/playground/output.txt",
    //     "w", stdout);
    // #endif
    clock_t z = clock();
    int test = 1;
    // cin >> test;
    while (test--) {
        solve();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}