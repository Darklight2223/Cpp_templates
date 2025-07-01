
vector<int> topologicalSort(int n,unordered_map<int, vector<int>>& adj, vector<int>& indegree) {
    vector<int> result;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);
        for (int u : adj[node]) {
            indegree[u]--;
            if (indegree[u] == 0) {
                q.push(u);
            }
        }
    }
    if (result.size() != n) {
        return {};
    }
    
    return result;
}
