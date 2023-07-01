class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> stops(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        minh.push({0, src, 0});

        while(!minh.empty()){
            auto vec = minh.top();
            minh.pop();
            int dist = vec[0];
            int node = vec[1];
            int steps = vec[2];
            if (steps > stops[node] || steps > k+1) continue;
            stops[node] = steps;
            if (node == dst) return dist;
            for(auto& [adjNode, price] : adj[node]){
                minh.push({dist+price, adjNode, steps+1});
            }
        }
    return -1;
    }
};