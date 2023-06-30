class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> indegree(graph.size(), 0);
        for(int i=0; i<graph.size(); i++){
            for(auto it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0; i<adj.size(); i++){
            if(!indegree[i]) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};