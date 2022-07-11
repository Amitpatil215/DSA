#include <bits/stdc++.h>
using namespace std;

#define n 10000

vector<int> parent(n);
vector<int> Rank(n, 0);

void initializeParent() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
int findParent(int node) {
    if (parent[node] == node) {
        return node;
    }

    // path compression step
    // assign a parent to all its childrens
    // otherwise every time we have to look recursively to find parent
    return parent[node] = findParent(parent[node]);
}

void unionn(int u, int v) {
    int parentOfU = findParent(u);
    int parentOfV = findParent(v);

    if (Rank[parentOfU] < Rank[parentOfV]) {
        parent[parentOfU] = v;
    } else if (Rank[parentOfU] > Rank[parentOfV]) {
        parent[parentOfV] = u;
    } else {
        parent[parentOfV] = u;
        Rank[parentOfU]++;
    }
}
int main() {
    initializeParent();
    unionn(1, 2);
    unionn(3, 4);
    if (findParent(2) == findParent(4)) {
        cout << "belong to same component";
    } else {
        cout << "belong to diff component";
    }
    return 0;
}
