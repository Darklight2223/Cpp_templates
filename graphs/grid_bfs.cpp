
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool isValid(int x, int y, int n, int m) { 
    return (x >= 0 && x < n && y >= 0 && y < m);
}

vector<vector<int>> bfs(vector<vector<int>>& grid,int x,int y) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[x][y] = 0;
    while(!q.empty()) {
        auto [nx, ny] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int newX = nx + dx[i];
            int newY = ny + dy[i];
            if(isValid(newX, newY, n, m) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                dist[newX][newY] = min(dist[newX][newY], dist[nx][ny] + 1);
                q.push({newX, newY});
            }
        }
    }
    return dist;
}
