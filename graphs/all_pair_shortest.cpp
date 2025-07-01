vector<vector<ll>> floyd_warshall(unordered_map<int, vector<pair<int,ll>>>& adj, int n) {

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, LLONG_MAX));
    for (int i = 1; i <= n; ++i) dist[i][i] = 0;

    for (auto i : adj) {
        int u = i.first;
        auto neighbors = i.second;
        for (auto j : neighbors) {
            int v = j.first;
            ll w = j.second;
            dist[u][v] = min(dist[u][v], w); 
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}


