class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> minh;
        minh.push({0, 0});
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        long long mod = 1e9 + 7;
        while(!minh.empty()){
            auto [dis, node] = minh.top();
            minh.pop();

            for(auto [adjNode, wt]: adj[node]){
                if(dis+wt < dist[adjNode]){
                    ways[adjNode] = ways[node];
                    dist[adjNode] = dis + wt;
                    minh.push({dist[adjNode], adjNode});
                }
                else if(dis + wt == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])% mod;
                }
            }
        }
        return ways[n-1];
    }
};