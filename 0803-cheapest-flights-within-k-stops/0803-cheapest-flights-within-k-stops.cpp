class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, INT_MAX);
        queue<pair<int,int>> q;
        q.push({src, 0});
        int stops =0;
        while(!q.empty() && stops <= k){
            int level = q.size();
            while(level--){
                auto [node, distance] = q.front();
                q.pop();
                for(auto& [adjNode, price]: adj[node]){
                    if(price+distance < dist[adjNode]){
                        dist[adjNode] = price + distance;
                        q.push({adjNode, dist[adjNode]});
                    }
                }
            }
            stops++;
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};