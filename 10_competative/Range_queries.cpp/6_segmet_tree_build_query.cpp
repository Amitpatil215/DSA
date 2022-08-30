/*
Max In An Interval - Range Query
Medium  Prev   Next
You are given an array(of integers) of length n.
You are required to answer q queries.
In each query u are given an interval l, r both inclusive and u have to find the
maximum element in this interval.

To do the above task u have to create a datastructure as follows :-

Implement the SegmentTree class:
1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
2. int query(int l, int r): return max in interval [l, r].

Can u do it in O(log(n)) or better Time Complexity.
Input Format
A number n
n1
n2
.. n number of elements
A number q
following q lines contains queries of format
l r
Output Format
for each query print a single integer in seperate line
Question Video

  COMMENTConstraints
1. 1 <= n, q <= 10^5
2. 0 <= l <= r < n
3. 10^9 <= arr[i] <= 10^9
4. all input and output will fit in 32bit signed integer
Sample Input
8
8
7
4
2
5
3
1
10
4
0 7
0 3
2 7
1 6
Sample Output
10
8
10
7

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

class segmentTree {
   public:
    // given array
    vector<int> arr;

    // to store segment tree
    vector<int> tree;
    // constructor
    segmentTree(int n, vector<int> arr) {
        this->arr = arr;
        tree = vector<int>(4 * n);
        // build the tree using given array
        buildTree(1, 0, n - 1);
        for (int i = 0; i < tree.size(); i++) {
            debug(i, tree[i]);
        }
    }
    void buildTree(int node, int start, int end) {
        // if we are left eith only one element the that would be max;
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        int left = node * 2;
        int right = node * 2 + 1;
        // build left and right sub tree
        buildTree(left, start, mid);
        buildTree(right, mid + 1, end);
        // store the max value from left and right tree
        tree[node] = max(tree[left], tree[right]);
    }

    // start and end denotes current nodes range
    // l and r denotes left and right range in the query
    int query(int node, int start, int end, int l, int r) {
        // when given l and r are out of range
        if (r < start || l > end) return INT_MIN;
        // if start and end is same
        if (start == end) {
            return tree[node];
        } else if (l <= start && end <= r) {
            // if l and r contains the range i.e start and end
            return tree[node];
        } else {
            int mid = (start + end) / 2;
            int left = query(node * 2, start, mid, l, r);
            int right = query((node * 2) + 1, mid + 1, end, l, r);
            return max(left, right);
        };
    }
};

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
    segmentTree segTree(n, arr);
    for (auto qu : query) {
        int l = qu.first;
        int r = qu.second;
        cout << segTree.query(1, 0, arr.size() - 1, l, r) << endl;
    }
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

/*
Test case
1 // no of test cases
8 // total numbers in array
8
7
4
2
5
3
1
10
4 // total no fo queries
0 7
0 3
2 7
1 6

Output

i : 0 |  tree[i] : 0
i : 1 |  tree[i] : 10
i : 2 |  tree[i] : 8
i : 3 |  tree[i] : 10
i : 4 |  tree[i] : 8
i : 5 |  tree[i] : 4
i : 6 |  tree[i] : 5
i : 7 |  tree[i] : 10
i : 8 |  tree[i] : 8
i : 9 |  tree[i] : 7
i : 10 |  tree[i] : 4
i : 11 |  tree[i] : 2
i : 12 |  tree[i] : 5
i : 13 |  tree[i] : 3
i : 14 |  tree[i] : 1
i : 15 |  tree[i] : 10
i : 16 |  tree[i] : 0
i : 17 |  tree[i] : 0
i : 18 |  tree[i] : 0
i : 19 |  tree[i] : 0
i : 20 |  tree[i] : 0
i : 21 |  tree[i] : 0
i : 22 |  tree[i] : 0
i : 23 |  tree[i] : 0
i : 24 |  tree[i] : 0
i : 25 |  tree[i] : 0
i : 26 |  tree[i] : 0
i : 27 |  tree[i] : 0
i : 28 |  tree[i] : 0
i : 29 |  tree[i] : 0
i : 30 |  tree[i] : 0
i : 31 |  tree[i] : 0
10
8
10
7


 */