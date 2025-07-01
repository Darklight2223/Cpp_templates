ll dijkstraWithkEdges(unordered_map<int, vector<pair<int,ll>>> &adj, int n, int src, int dst, int k) {
    vector<vector<ll>> dist(n + 1, vector<ll>(k + 1, LLONG_MAX));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

    dist[src][0] = 0;
    pq.push({0, src, 0});

    while (!pq.empty()) {
        auto [cost, u, steps] = pq.top(); pq.pop();
        if (steps > k) continue;

        for (auto [v, w] : adj[u]) {
            if (steps + 1 <= k && cost + w < dist[v][steps + 1]) {
                dist[v][steps + 1] = cost + w;
                pq.push({cost + w, v, steps + 1});
            }
        }
    }

    ll res = *min_element(dist[dst].begin(), dist[dst].end()); // for <=k edges
    // ll res = dist[dst][k]; // for exactly k edges
    return (res == LLONG_MAX ? -1 : res);
}