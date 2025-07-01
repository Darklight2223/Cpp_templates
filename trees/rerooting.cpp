vector<int> tree[n];            // Adjacency list of the tree
vector<int> subtree_size(n);    // Size of subtree rooted at each node
vector<int> dist_sum(n);        // Total distance from node u to its subtree nodes
vector<int> ans(n);             // Final answer: sum of distances from u to all nodes

void dfs1(int u, int p) {
    subtree_size[u] = 1;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        dist_sum[u] += dist_sum[v] + subtree_size[v];
    }
}

void dfs2(int u, int p) {
    for (int v : tree[u]) {
        if (v == p) continue;
        ans[v] = ans[u] - subtree_size[v] + (n - subtree_size[v]);

        dfs2(v, u);
    }
}
// this is to want to compute, for every node u, the sum of distances from u to all other nodes.