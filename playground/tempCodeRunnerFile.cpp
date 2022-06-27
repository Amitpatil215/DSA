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
    int nodes, edges;
    cin >> nodes >> edges;
    int u, v;
    vector<int> freq(nodes + 1, 0);
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;
        freq[u] += 1;
        freq[v] += 1;
    }
    int spclNodesCount = 0;
    for (int i = 1; i < freq.size(); i++) {
        if (freq[i] == 1) {
            spclNodesCount++;
        }
    }
    // debug(spclNodesCount);
    int remainingNodes = nodes - spclNodesCount;
    cout << remainingNodes * spclNodesCount << endl;
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