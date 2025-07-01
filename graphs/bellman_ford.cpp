
vector<ll> bellman_ford(unordered_map<int, vector<pair<int,ll>>> &adj, int n, int s) {
    vector<ll> dist(n + 1, LLONG_MAX);
    dist[s] = 0;

    for(int i = 1; i<n; i++) {
        for(auto it : adj) {
            int u = it.first;
            for(auto edge : it.second) {
                int v = edge.first;
                ll w = edge.second;
                if(dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for(auto it : adj) {
        int u = it.first;
        for(auto edge : it.second) {
            int v = edge.first;
            ll w = edge.second;
            if(dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                return {};
            }
        }
    }
    return dist;
}

