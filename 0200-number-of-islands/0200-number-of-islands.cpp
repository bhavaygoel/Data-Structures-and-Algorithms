class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i <= 3; i++) {
                    int delrow = dr[i];
                    int delcol = dc[i];
                    if (delrow != delcol && (row + delrow) >= 0 && (row + delrow) < grid.size() &&
                        (col + delcol) >= 0 && (col + delcol) < grid[0].size() &&
                        grid[row + delrow][col + delcol] == '1' && !vis[row + delrow][col + delcol]) {
                        q.push({row + delrow, col + delcol});
                        vis[row + delrow][col + delcol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};