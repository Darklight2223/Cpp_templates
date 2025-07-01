
vector<int> bfs(unordered_map<int,vector<int>>& adj,int n,int s) {
    queue<int> q;
    vector<int> dist(n+1,0);
    vector<bool> visited(n+1,false);
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int u : adj[node]) {
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[node] + 1;
                q.push(u);
            }
        }
    }
    return dist;
}
