const int LOG = 20;
vector<int> tree[N];
int up[N][LOG];     // up[u][k] = 2^k-th ancestor of u
int depth[N]; 

void dfs(int node, int parent) {
    up[node][0] = parent;
    for (int i = 1; i < LOG; ++i) {
        if (up[node][i - 1] != -1) up[node][i] = up[up[node][i - 1]][i - 1];
        else up[node][i] = -1;
    }

    for (int child : tree[node]) {
        if (child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOG - 1; i >= 0; --i)
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) u = up[u][i];

    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != -1 && up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];  
}

// to find the distance between two nodes
int get_distance(int u, int v) {
    int ancestor = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[ancestor];
}
