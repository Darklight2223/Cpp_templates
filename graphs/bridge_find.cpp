
void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<pair<int, int>> &bridges, unordered_map<int, vector<int>> &adj) {
    tin[node] = low[node] = timer++;
    
    for (int v : adj[node]) {
        if (v == parent) continue; 
        if (tin[v] == -1) { 
            dfs(v, node, timer, tin, low, bridges, adj);
            low[node] = min(low[node], low[v]);
            if (low[v] > tin[node]) {
                bridges.push_back({node, v});
            }
        } 
        else {
            low[node] = min(low[node], tin[v]);
        }
    }
}

vector<pair<int, int>> findBridges(unordered_map<int, vector<int>> &adj,int n) {
    vector<int> tin(n + 1, -1), low(n + 1, -1);
    vector<pair<int, int>> bridges;
    int timer = 0;

    for (int i = 1; i <= n; i++) {
        if (tin[i] == -1) {
            dfs(i, -1, timer, tin, low, bridges, adj);
        }
    }
    
    return bridges;
}

