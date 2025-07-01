
void dfs(int node, int parent, int &timer, vector<int> &tin, vector<int> &low, vector<bool> &isArticulation, unordered_map<int, vector<int>> &adj) {
    tin[node] = low[node] = timer++;
    int children = 0;

    for (int v : adj[node]) {
        if (v == parent) continue;
        if (tin[v] == -1) {
            dfs(v, node, timer, tin, low, isArticulation, adj);
            low[node] = min(low[node], low[v]);

            if (low[v] >= tin[node] && parent != -1) {
                isArticulation[node] = true;
            }
            children++;
        } 
        else {
            low[node] = min(low[node], tin[v]);
        }
    }

    if (parent == -1 && children > 1) {
        isArticulation[node] = true;
    }
}

vector<int> findArticulationPoints(unordered_map<int, vector<int>> &adj, int n) {
    vector<int> tin(n + 1, -1), low(n + 1, -1);
    vector<bool> isArticulation(n + 1, false);
    int timer = 0;
    for (int i = 1; i <= n; ++i) {
        if (tin[i] == -1) {
            dfs(i, -1, timer, tin, low, isArticulation, adj);
        }
    }
    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (isArticulation[i]) result.push_back(i);
    }
    return result;
}

