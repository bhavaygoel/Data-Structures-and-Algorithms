class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int len = 1;
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row == n - 1 && col == n - 1) {
                    return len;
                }

                for (int i = 0; i < 8; i++) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
                    if (newRow >= 0 && newRow < n && newCol >= 0 &&
                        newCol < n && grid[newRow][newCol] == 0) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 1;
                    }
                }
            }
            len++;
        }

        return -1;
    }
};
