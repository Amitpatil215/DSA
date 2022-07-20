/*

Reconstructing a Sequence

Given a sequence originalSeq and an array of sequences, write a method to find
if originalSeq can be uniquely reconstructed from the array of sequences.

Unique reconstruction means that we need to find if originalSeq is the only
sequence such that all sequences in the array are subsequences of it.

Example 1:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
[1, 2, 3, 4], in other words, all the given sequences uniquely define the order
of numbers in the 'originalSeq'.

Example 2:

Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely
reconstruct [1, 2, 3, 4]. There are two possible sequences we can construct from
the given sequences: 1) [1, 2, 3, 4] 2) [1, 2, 4, 3]

Example 3:

Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct
[3, 1, 4, 2, 5].
Solution #
Since each sequence in the given array defines the ordering of some numbers, we
need to combine all these ordering rules to find two things:

Is it possible to construct the originalSeq from all these rules?
Are these ordering rules not sufficient enough to define the unique ordering of
all the numbers in the originalSeq? In other words, can these rules result in
more than one sequence? Take

Example-1:

originalSeq: [1, 2, 3, 4], seqs:[[1, 2], [2, 3], [3, 4]]
The first sequence tells us that ‘1’ comes before ‘2’; the second sequence tells
us that ‘2’ comes before ‘3’; the third sequence tells us that ‘3’ comes before
‘4’. Combining all these sequences will result in a unique sequence: [1, 2, 3,
4].

The above explanation tells us that we are actually asked to find the
topological ordering of all the numbers and also to verify that there is only
one topological ordering of the numbers possible from the given array of the
sequences.

This makes the current problem similar to Tasks Scheduling Order with two
differences:

We need to build the graph of the numbers by comparing each pair of numbers in
the given array of sequences. We must perform the topological sort for the graph
to determine two things: Can the topological ordering construct the originalSeq?
That there is only one topological ordering of the numbers possible. This can be
confirmed if we do not have more than one source at any time while finding the
topological ordering of numbers.

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
    int n;
    cin >> n;
    int original[n];
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    // build adjacency
    vector<int> adjList[n + 1];

    int nsubSeqeuence;
    cin >> nsubSeqeuence;
    for (int i = 0; i < nsubSeqeuence; i++) {
        int entry;
        cin >> entry;

        int prev;
        cin >> prev;
        for (int j = 1; j < entry; j++) {
            int v;
            cin >> v;
            adjList[prev].push_back(v);
            prev = v;
        }
    }

    // find indegree
    vector<int> indegree(n + 1, 0);
    for (auto tuple : adjList) {
        for (auto nbrs : tuple) {
            indegree[nbrs]++;
        }
    }

    // push 0 indegree nodes to the queue
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        // if there are more than one 0 indegree then we cant build
        // unique sequence
        if (q.size() > 1) {
            cout << false << endl;
            return;
        }
        // if original and our current topo sorted sequence doesnt
        // have same value then also sequence is not possible
        if (original[ans.size()] != q.front()) {
            cout << false << endl;
            return;
        }
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto nbr : adjList[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }

    /* cout << "TOPO SORT" << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
     */

    // if generated topo sort is not equal to lenght of original
    // sequence then also we cant generate a subsequence
    if (ans.size() == n) {
        cout << true << endl;
    } else {
        cout << false << endl;
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