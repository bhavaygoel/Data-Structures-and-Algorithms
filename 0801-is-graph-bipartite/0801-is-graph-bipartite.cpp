class Solution {
private:
    bool dfs(int start,int col, vector<vector<int>>& graph, vector<int>& color) {
        color[start] = col;
        for(auto it: graph[start]){
            if(color[it] == -1){
                if(!dfs(it, !col, graph, color)) return false;
            }
            else if(color[it] == col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1 && !dfs(i,0, graph, color)) {
                return false;
            }
        }
        return true;
    }
};
