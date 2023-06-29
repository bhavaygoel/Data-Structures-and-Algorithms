class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis){
        vis[node] = 2;
        for(auto i: graph[node]){
            if(!vis[i]){
                if(dfs(i, graph, vis)) return true;
            }
            else if(vis[i] == 2) return true;
        }
        vis[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
            if(!vis[i]){
                dfs(i, graph,vis);
            }
        }
        vector<int> ans;
        for(int i = 0; i< vis.size(); i++){
            if(vis[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};