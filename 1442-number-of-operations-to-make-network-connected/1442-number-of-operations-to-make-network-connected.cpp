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
    int makeConnected(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) {
            return -1;
        }
        DisjointSet ds(n);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) != ds.findParent(v)){
                ds.unionS(u, v);
            }
        }
        int comp = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                comp++;
            }
        }
        int ans = comp - 1;
        return ans;
    }
};