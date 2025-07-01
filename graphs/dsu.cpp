
int find(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = find(parent[node], parent); 
    }
    return parent[node];
}   

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);
    
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } 
        else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } 
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

bool areConnected(int u, int v, vector<int>& parent) {
    return find(u, parent) == find(v, parent);
}

void initializeDSU(int n, vector<int>& parent, vector<int>& rank) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i; 
    }
}
//initializeDSU(n, parent, rank);
