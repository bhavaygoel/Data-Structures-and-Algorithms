//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet {
 public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findParent(int node){
        if(node == parent[node]) return node;
        
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;
        vector<int> ans;
        for(auto& it: operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col]){
                ans.push_back(count);
                continue;
            }
            else{
                vis[row][col] = 1;
                count++;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr < n && nc < m && min(nr, nc) >=0){
                        if(vis[nr][nc]){
                            int nodeno = row*m + col;
                            int adjN = nr*m + nc;
                            if(ds.findParent(nodeno) != ds.findParent(adjN)){
                                count--;
                                ds.unionS(nodeno, adjN);
                            }
                        }
                    }
                }
                ans.push_back(count);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends