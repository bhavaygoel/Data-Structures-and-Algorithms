class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair <pair<int,int>, int> > q;

        for(int i=0; i< n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({ {i, j}, 0});
                }
            }
        }
        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(min(nrow, ncol) >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1){
                    grid[nrow][ncol] = 2;
                    q.push({{nrow, ncol}, t+1});
                }
            }
        }
        for(int i=0; i< n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;

    }
};