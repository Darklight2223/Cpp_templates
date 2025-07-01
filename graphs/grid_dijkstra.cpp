
int dx[] = {-1, 0, 1, 0}; 
int dy[] = {0, 1, 0, -1};

vector<vector<ll>> dijkstraGrid(vector<vector<ll>> &grid, int sx, int sy) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<ll>> dist(n, vector<ll>(m, LLONG_MAX));
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<>> pq;

    dist[sx][sy] = grid[sx][sy];
    pq.push({grid[sx][sy], {sx, sy}});

    while (!pq.empty()) {
        auto [cost, cell] = pq.top(); pq.pop();
        int x = cell.first, y = cell.second;

        if (cost > dist[x][y]) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                ll newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    return dist;
}
