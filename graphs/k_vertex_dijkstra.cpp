const ll INF = 1e18;
vector<vector<ll>> bitmaskDijkstraFromSource(int n, unordered_map<int, vector<pair<int, ll>>>& adj, vector<int>& special, int source) {
    
    int k = special.size();
    unordered_map<int, int> specialIndex;
    for (int i = 0; i < k; i++) {
        specialIndex[special[i]] = i;
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(1 << k, INF));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    
    // for (int i = 0; i < K; ++i) {
    //     int node = special[i];
    //     int mask = (1 << i);
    //     dist[node][mask] = 0;
    //     pq.push({0, node, mask});
    // } 
    // Use if we are starting from all special nodes

    
    // Here we start from a single source node
    int startMask = 0;
    if (specialIndex.count(source)) {
        startMask = (1 << specialIndex[source]);
    }

    dist[source][startMask] = 0;
    pq.push({0, source, startMask});

    while (!pq.empty()) {
        auto [cost, u, mask] = pq.top(); pq.pop();
        if (cost > dist[u][mask]) continue;

        for (auto [v, w] : adj[u]) {
            int newMask = mask;
            if (specialIndex.count(v)) {
                newMask |= (1 << specialIndex[v]);
            }

            if (dist[v][newMask] > cost + w) {
                dist[v][newMask] = cost + w;
                pq.push({dist[v][newMask], v, newMask});
            }
        }
    }

    return dist;
}


