/*
Moksh And His Girlfriend
https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/range-queries/moksh-and-his-girlfriend/ojquestion
Recently Moksh(HR of Pepcoding) invented a serum which can increase height of
plant by 1 unit. Moksh's girlfriend birthday is next month. He is planning
something amazing as a gift for her.His girlfriend's favourite Integer is M.

Initially Moksh has N (1 to N) no. of beautiful Rose plants, Each plant can have
an Integer height,Initially the height of each plant is zero. Subhesh gives
Moksh Q number of operations,In each operation Moksh got two integer start and
end and he increases the height of all the plants between start and end position
(including start and end) by 1. As Moksh wasn't happy with the pattern of height
of the plants formed, He went to Rajneesh and asked him to remove any 1
operation from the Q operations such that the count of plants with height M is
maximum possible. Output the maximum possible number of plants with height M.

Expected Complexity : O(n+q)
Input Format
First line contains three space separated integer N(no. of Rose plants),
Q(number of operations), M. Each of the next Q lines contains two
space-separated integers L and R describing one operation. Output Format print a
single line containing one integer - the maximum possible number of Trees with
height M. Question Video

  COMMENTConstraints
Constraint :
2<=N<=100000.
2<=Q<=100000.
1<=M1<=L<=R<=N.
Sample Input
10 3 2
2 6
4 9
1 4
Sample Output
3

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