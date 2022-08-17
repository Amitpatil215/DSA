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

void update(int index, int val, vector<int> &fenwick) {
    int n = fenwick.size();

    while (index <= n) {
        fenwick[index] += val;
        // next impact of this value will be on the upper side
        // we can find next index by adding most significant bit to the current
        // index
        index = index + (index & -index);
    }
}

int find(int index, vector<int> &fenwick) {
    int sum = 0;
    while (index > 0) {
        // debug(index);
        sum += fenwick[index];

        // we can find next index by substracting most significant bit to the
        // current index
        index = index - (index & -index);
    }
    return sum;
}

void generateFenwickTree(vector<int> &fenwick, vector<int> &arr) {
    int n = arr.size();
    // we just simply call update for every index and it will update
    // its impact on every relavent index
    for (int i = 1; i <= n; i++) {
        update(i, arr[i], fenwick);
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<pair<char, pair<int, int>>> query;
    for (int i = 0; i < q; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        query.push_back({c, {l, r}});
    }

    // fenwick tree implementaion
    vector<int> fenwick(n + 1, 0);
    generateFenwickTree(fenwick, arr);

    // update sum in fenwick tree
    for (auto qr : query) {
        char c = qr.first;
        if (c == 'u') {
            // update query
            int index = qr.second.first;
            int val = qr.second.second;
            update(index, val, fenwick);
        } else {
            int left = qr.second.first;
            int right = qr.second.second;
            cout << find(right, fenwick) - find(left - 1, fenwick) << endl;
        }
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