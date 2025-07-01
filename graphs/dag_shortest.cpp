
vector<ll> dag_shortest_path(unordered_map<int, vector<pair<int, ll>>> &adj, int n, int src) {
    vector<ll> dist(n + 1, LLONG_MAX);
    vector<int> inDegree(n + 1, 0);
    vector<int> topo;
    queue<int> q;

    for (auto i : adj) {
        int u=i.first;
        auto neighbors=i.second;
        for (auto j : neighbors)
            inDegree[j.first]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);

        for (auto i : adj[u]) {
            int v=i.first;
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }

    if (topo.size() != n) {
        return {};
    }

    dist[src] = 0;
    for (int u : topo) {
        if (dist[u] == LLONG_MAX) continue;
        for (auto i : adj[u]) {
            int v = i.first;
            ll w = i.second;
            if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    return dist;
}


