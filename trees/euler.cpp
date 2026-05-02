int n;
int timer=0;
vector<int> tin(n+1), tout(n+1), arr(n+1);
void dfs(unordered_map<int,vector<int>>& g, vector<int>& val, int u, int p) {
    tin[u] = timer;
    arr[timer] = val[u]; 
    timer++;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(g, val, v, u);
        }
    }
    tout[u] = timer-1;
}

// For subtree queries,we can use the range [tin[u], tout[u]] to represent the subtree of node u.
// For example, to find sum of values in subtree of node u with dynamic updates,we can use 
// segment tree on range [tin[u], tout[u]] to get the sum of values in the subtree of node u.