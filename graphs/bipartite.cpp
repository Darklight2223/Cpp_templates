
bool isbipartite(unordered_map<int, vector<int>>& adj, int n) {
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0; 
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int v : adj[node]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[node];
                        q.push(v);
                    } 
                    else if (color[v] == color[node]) {
                        return false; 
                    }
                }
            }
        }
    }
    return true; 
}

