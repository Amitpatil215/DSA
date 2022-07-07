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
#include <bits/stdc++.h>
using namespace std;

bool detectCycleDFS(int startNode, int parentNode, vector<int> &visited,
                    vector<vector<int>> &adjList) {
    visited[startNode] = true;
    for (auto nbr : adjList[startNode]) {
        if (!visited[nbr]) {
            bool isCycleDetected =
                detectCycleDFS(nbr, startNode, visited, adjList);
            if (isCycleDetected) {
                debug("if true");
                return true;
            };
        } else {
            // if node is already visited and its not visited by its parent
            // then we have a cycle
            if (parentNode != -1 && nbr != parentNode) {
                debug("else true");
                return true;
            };
        }
    }
    return false;
}

void solve() {
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjList(vertices, vector<int>());

    for (int i = 0; i < vertices; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // check dfs cycle for every component
    vector<int> visited(vertices, false);
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (detectCycleDFS(i, -1, visited, adjList)) {
                cout << "True" << endl;
                return;
            }
        }
    }
    cout << "False" << endl;

    return;
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