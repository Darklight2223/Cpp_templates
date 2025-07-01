
int find(int node,vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = find(parent[node], parent); 
    }
    return parent[node];
}

void unionSets(int u,int v,vector<int>& parent,vector<int>& rank) {
    int rootU = find(u,parent);
    int rootV = find(v,parent);
    if(rootU!=rootV) {
        if(rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } 
        else if(rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } 
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

bool areConnected(int u,int v,vector<int>& parent) {
    return find(u,parent) == find(v,parent);
}

void initializeDSU(int n,vector<int>& parent,vector<int>& rank) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
    }
}

ll kruskal(unordered_map<int,vector<pair<int,ll>>> &adj, int n) {
    vector<pair<ll, pair<int, int>>> edges;
    for (auto &it : adj) {
        int u = it.first;
        for (auto &v : it.second) {
            edges.push_back({v.second, {u, v.first}});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    vector<int> parent, rank;
    initializeDSU(n, parent, rank);
    
    ll ans = 0;
    for (auto &edge : edges) {
        ll weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (!areConnected(u, v, parent)) {
            unionSets(u, v, parent, rank);
            ans += weight;
        }
    }
    
    return ans;
}

