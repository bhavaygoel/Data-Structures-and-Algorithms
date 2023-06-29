class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        vector<int> indegree(n, 0);
        vector<vector<int>> prerequisites(n);
        for (auto prerequisite : adj) {
            prerequisites[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!indegree[i]) q.push(i);
        }
        int count =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto it: prerequisites[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        if(count == n) return true;
        return false;
    }
};