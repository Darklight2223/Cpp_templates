
vector<ll> dijkstra(unordered_map<int, vector<pair<int,ll>>> &adj, int n, vector<int> &sources) {
    vector<ll> ans(n + 1, LLONG_MAX);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    for (int s : sources) {
        ans[s] = 0;
        pq.push({0, s});
    }

    while (!pq.empty()) {
        auto x = pq.top();
        int u = x.second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto i : adj[u]) {
            int v = i.first;
            ll w = i.second;
            if (ans[v] > ans[u] + w) {
                ans[v] = ans[u] + w;
                pq.push({ans[v], v});
            }
        }
    }

    return ans;
}

