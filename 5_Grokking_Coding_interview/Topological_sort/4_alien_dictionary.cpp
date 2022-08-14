/*

Alien dictionary

venice 85

Sample Input 1 :
2
3
a aa aaa
3
a b c
Sample Output 1 :
true
true
Explanation For Sample Output 1 :
For the first test case, the words are 'a', 'aa', and 'aaa'. Since the only
unique character here is 'a', so the array to be returned will just be ['a'].
The 'true' that is being printed just signifies that the output returned by the
function is valid.

For the second test case, the words are 'a', 'b', and 'c'. The unique characters
here are 'a', 'b', and 'c' (in that order), so the array to be returned will be
['a', 'b', 'c'] Sample Input 2 :
2
3
caa aaa aab
2
aa aab
Sample Output 2 :
true
true

 */

#include <bits/stdc++.h>
vector<char> getAlienLanguage(string* dictionary, int n) {
    if (n == 0) return vector<char>();
    if (n == 1) {
        unordered_map<char, int> m;
        vector<char> ans;
        for (auto x : dictionary[0]) {
            if (m.count(x) == 0) {
                ans.push_back(x);
            }
            m[x] = 1;
        }
        return ans;
    }
    vector<int> adjList[26];
    string prev = dictionary[0];
    // compare two adjacent string and find first miss match character and make
    // a directed edge b/w them
    set<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        string curr = dictionary[i];
        int j = 0;
        while (j < min(prev.length(), curr.length()) && prev[j] == curr[j]) {
            j++;
        }

        int u = prev[j] - 'a';
        int v = curr[j] - 'a';
        if (u != v) edges.insert({u, v});
        prev = curr;
    }
    // build adjacency list
    for (auto edge : edges) {
        adjList[edge.first].push_back(edge.second);
    }
    // find topological sort
    //  generate indegree

    vector<int> indegree(26, -1);
    for (int i = 0; i < 26; i++) {
        if (adjList[i].size() > 0)
            if (indegree[i] == -1) indegree[i] = 0;
        for (auto nbr : adjList[i]) {
            if (indegree[nbr] == -1) indegree[nbr] = 0;
            indegree[nbr]++;
        }
    }

    queue<int> q;
    // insert all the nodes having indegree 0
    int i = 0;
    for (auto x : indegree) {
        if (x == 0) {
            q.push(i);
        }
        i++;
    }

    // find toposort
    vector<char> topo;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        char c = (char)(front + 'a');
        topo.push_back(c);
        // reduce indegree of neighbours by 1
        for (auto nbr : adjList[front]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    cout << endl;
    return topo;
}
