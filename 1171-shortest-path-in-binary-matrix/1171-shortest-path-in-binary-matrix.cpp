class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<pair<int, int>, int>> q;
        // { {r, c}, len}
        q.push({{0, 0}, 1});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int len = q.front().second;
            q.pop();
            if (grid[row][col]) {
                continue;
            }
            if (row == n - 1 && col == n - 1) {
                return len;
            }
            vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
            vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};
            for (int i = 0; i < 8; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 &&
                     newCol < n && !vis[newRow][newCol]
                         && !grid[newRow][newCol]) {
                    q.push({{newRow, newCol}, len + 1});
                    vis[newRow][newCol] = 1;
                }
            }
        }
        return -1;
    }
};
