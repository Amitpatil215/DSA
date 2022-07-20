/*
There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] =
[ai, bi] indicates that you must take course bi first if you want to take course
ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first
take course 1. Return true if you can finish all courses. Otherwise, return
false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
To take course 1 you should have finished course 0, and to take course 0 you
should also have finished course 1. So it is impossible.


Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
 */

class Solution {
   public:
    bool isTopoSortPossible(int numCourses,
                            vector<vector<int>>& prerequisites) {
        // build adjaceny list
        vector<int> adjList[numCourses];
        for (auto pre : prerequisites) {
            int u = pre[0];
            int v = pre[1];
            adjList[u].push_back(v);
        }

        // find indegree
        vector<int> indegree(numCourses, 0);
        for (auto tuple : adjList) {
            for (auto nbrs : tuple) {
                indegree[nbrs]++;
            }
        }

        // push 0 indegree nodes to the queue
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
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

        if (ans.size() == numCourses) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // if we able to find topo sort then it is possible otherwise not
        return isTopoSortPossible(numCourses, prerequisites);
    }
};