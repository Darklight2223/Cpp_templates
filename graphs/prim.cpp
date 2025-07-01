
ll prim(unordered_map<int, vector<pair<int,ll>>> &adj, int n,int s) {
    ll ans = 0;
    vector<bool> visited(n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto x = pq.top();
        ll weight = x.first;
        int u = x.second;
        pq.pop();
        
        if(visited[u]) continue; 
        visited[u] = true; 
        ans += weight;
        
        for(auto i : adj[u]) {
            if(!visited[i.first]) {
                int v = i.first;
                ll w = i.second;
                pq.push({w, v}); 
            }
        }
    }
    return ans;
}

