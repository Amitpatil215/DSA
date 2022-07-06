/*
https://www.youtube.com/watch?v=7JwGNqNDevM

Road Blockage

There are N cities in Geekland numbered 0, 1,.., N - 1. There are (N-1)
bidirectional roads, the i road connects city Edge[i][0] and Edge[i][1]. You can
consider the length of each road as 1 unit. At least one path can be found
between any two cities in Geekland. People of Geekland love ordering from
Amazon. Its warehouse is located in city 0. But there is a rebel group in the
country that can block any road and disrupt deliveries. Geek is a software
engineer at Amazon. 
He wants to develop a software that discards all the cities
where delivery is not possible due to road blockage. For the remaining cities,
the software calculates the maximum distance an item has to travel from city 0
to the customer living in any connected city x. 

You are given Q queries; in the
ith query, the road connecting city query[i][0] and query[i][1] is blocked by
the rebel group. Help Geek to find the maximum distance for each query. 

Input:
N = 5, Q = 2
Edge[][] = {{0, 1},
            {0, 2},
            {1, 3},
            {1, 4}}
query = {{0, 1},
         {1, 4}}
Output:
1 2
Explanation:
Geekland looks like:
            0
           / \
         1    2
       /   \
     3      4
Query 1: the road connecting (0,1)
is blocked. Only people living in
city 0 and 2 can place delivery orders.
For city 0, distance = 0.
For city 2, distance = 1.
Maximum (city 0, city 1) = 1

Query 2: The road connecting
(1, 4) is blocked. Only people living in
city 0,1,2 and 3 can place delivery orders.
For city 0, distance = 0.
For city 1, distance = 1.
For city 2, distance = 1.
For city 3, distance = 2.
A maximum distance of 2 has to be travelled
for people of city 3. 0 -> 1 -> 3

Input: N = 3, Q = 1
Edge[][] = {{0, 1},
            {0, 2}}
query[][] = {{0, 1}}
Output: 1
Explanation:
Geekland looks like:
              0
            /   \
           1     2
           */

class Solution {
   public:
    vector<int> eulerTour;

    void dfs(int node, int level, vector<bool> &visited,
             vector<vector<int>> &adjList, int levels[]) {
        visited[node] = true;
        levels[node] = level;
        eulerTour.push_back(node);

        // sorting just to get output according to dry run
        // sort(adjList[node].begin(),adjList[node].end());

        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, level + 1, visited, adjList, levels);
            }
        }
        eulerTour.push_back(node);
    }

    vector<int> solve(int N, int Q, vector<vector<int>> &Edge,
                      vector<vector<int>> &query) {
        vector<vector<int>> adjList(N, vector<int>(N));
        // build a graph
        for (auto edge : Edge) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(N, false);
        int levels[N];
        // dfs for filling level and euler tour
        dfs(0, 0, visited, adjList, levels);

        // store start and end index of every node in euler tour
        map<int, int> start, end;
        int index = 0;

        //[Debug] Print Euler tour
        // for(auto x:eulerTour){
        //     cout<<x<<" ";
        // }
        // cout<<endl;

        for (auto node : eulerTour) {
            if (start.count(node) == 0) {
                start[node] = index;
            }
            end[node] = index;
            index++;
        }

        // find prefix max of levels
        vector<int> prefixMax(eulerTour.size());
        int maxVal = INT_MIN;
        for (int i = 0; i < eulerTour.size(); i++) {
            maxVal = max(maxVal, levels[eulerTour[i]]);
            prefixMax[i] = maxVal;
        }
        // find suffix max
        vector<int> suffixMax(eulerTour.size());
        maxVal = INT_MIN;
        for (int i = eulerTour.size() - 1; i >= 0; i--) {
            maxVal = max(maxVal, levels[eulerTour[i]]);
            suffixMax[i] = maxVal;
        }

        // now anser every query
        vector<int> ans;
        for (auto q : query) {
            // find which one is at more deper level
            // remove subtree with that root node using euler tour
            int maxLeveNodeIndex;
            if (levels[q[0]] > levels[q[1]]) {
                maxLeveNodeIndex = q[0];
            } else {
                maxLeveNodeIndex = q[1];
            }

            int startIndexInEulerTour = start[maxLeveNodeIndex];
            int endIndexInEulerTour = end[maxLeveNodeIndex];
            // cout<<startIndexInEulerTour<<" "<<endIndexInEulerTour<<"
            // "<<prefixMax[startIndexInEulerTour-1]<<"
            // "<<suffixMax[endIndexInEulerTour+1]<<endl;
            int distance = max(prefixMax[startIndexInEulerTour - 1],
                               suffixMax[endIndexInEulerTour + 1]);
            ans.push_back(distance);
        }
        return ans;
    }
};