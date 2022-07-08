/*
Shortest Path in undirected graph having unit weight
venice 67

we will print shortest distance to reach to every other node form source 
node
 */
void BFS(vector<int> adj[], int N, int src) {
    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbr : adj[node]) {
            // +1 cause we have an edge from current node to its neighbour
            if (dist[node] + 1 < dist[nbr]) {
                dist[nbr] = dist[node] + 1;
                q.push(nbr);
            }
        }
    }
    for (int i = 0; i < N; i++) cout << dist[i] << " ";
}