//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int node,vector<vector<int>>& isConnected,vector<bool>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = true;

        while(!q.empty()){
            node = q.front();
            q.pop();

            for(int i=0; i< isConnected.size(); i++){
                if(isConnected[node][i] && !vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count=0;
        int n = adj.size();
        vector<bool> vis(n);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                bfs(i, adj, vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends