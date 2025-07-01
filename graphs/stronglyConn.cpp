
void dfs1(unordered_map<int, vector<int>>& adj, int node, vector<bool>& visited,stack<int>& st) {
    visited[node] = true;
    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs1(adj, v, visited, st);
        }
    }
    st.push(node);
}

void dfs2(unordered_map<int, vector<int>>& adj, int node, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int v : adj[node]) {
        if (!visited[v]) {
            dfs2(adj, v, visited, component);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, unordered_map<int, vector<int>>& adj) {
    stack<int> st;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(adj, i, visited, st);
        }
    }

    unordered_map<int, vector<int>> transposed;
    for (auto& pair : adj) {
        int u = pair.first;
        for (int v : pair.second) {
            transposed[v].push_back(u);
        }
    }

    vector<vector<int>> sccs;
    fill(visited.begin(), visited.end(), false);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(transposed, node, visited,component);
            sccs.push_back(component);
        }
    }
    return sccs;
}

// Function to find the minimum number of edges to add to make the graph strongly connected
int minimumedgestostronglyconnected(unordered_map<int,vector<int>>& adj,int n) {
    vector<vector<int>> sccs = stronglyConnectedComponents(n, adj);
    if (sccs.size() == 1) {
        return 0; 
    }
    
    int numSCCs = sccs.size();
    vector<int> inDegree(numSCCs, 0);
    vector<int> outDegree(numSCCs, 0);
    unordered_map<int, int> componentIndex;

    for (int i = 0; i < numSCCs; i++) {
        for (int node : sccs[i]) {
            componentIndex[node] = i;
        }
    }

    for (auto& pair : adj) {
        int u = pair.first;
        for (int v : pair.second) {
            int uComp = componentIndex[u];
            int vComp = componentIndex[v];
            if (uComp != vComp) {
                outDegree[uComp]++;
                inDegree[vComp]++;
            }
        }
    }

    int sources = 0, sinks = 0;
    for (int i = 0; i < numSCCs; i++) {
        if (inDegree[i] == 0) sources++;
        if (outDegree[i] == 0) sinks++;
    }
    return max(sources, sinks);
}
