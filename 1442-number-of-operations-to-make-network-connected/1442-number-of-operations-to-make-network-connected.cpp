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
        DisjointSet ds(n);
        int extra = 0;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            if(ds.findParent(u) == ds.findParent(v)){
                extra++;
            }
            else{
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
        if(ans <= extra) return ans;
        return -1;
    }
};