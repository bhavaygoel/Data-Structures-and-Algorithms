class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
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
        if(ans.size() == n) return ans;
        return {};
    }
};