class DisjointSet{
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionS(int u, int v){
        int up = findParent(u);
        int vp = findParent(v);
        if(up == vp) return;
        if(size[up] > size[vp]){
            parent[vp] = up;
            size[up] += size[vp];
        }
        else{
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                if(grid[row][col] == 0) continue;
                else{
                    for(int i=0; i<4; i++){
                        int nr = row + dr[i];
                        int nc = col + dc[i];
                        if(min(nr, nc) >= 0 && max(nr, nc) < n && grid[nr][nc]){
                            ds.unionS(row*n+col, nr*n+nc);
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<n; col++){
                set<int> components;
                if(grid[row][col] == 1) continue;
                else{
                    for(int i=0; i<4; i++){
                        int nr = row + dr[i];
                        int nc = col + dc[i];
                        if(min(nr, nc) >= 0 && max(nr, nc) < n && grid[nr][nc]){
                            components.insert(ds.findParent(nr*n + nc));
                        }
                    }
                }
                int size = 0;
                for(auto it: components){
                    size += ds.size[it];
                }
                size++;
                ans = max(ans, size);
            }
        }
        return ans == 0 ? n*n : ans;
    }
};