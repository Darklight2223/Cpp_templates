vector<int> subtree_sum(n+1); // To store the sum of values in each subtree

void dfs(int node,int parent) {
    subtree_sum[node] = node_values[node]; // subtree_size[node] = 1; // Initialize the size of the subtree
    for (int child : tree[node]) {  
        if (child != parent) {
            dfs(child, node);
            subtree_sum[node] += subtree_sum[child];
        }
    }
}