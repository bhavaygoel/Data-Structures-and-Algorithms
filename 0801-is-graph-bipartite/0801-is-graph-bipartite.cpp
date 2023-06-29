class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int i = 0; i < graph[node].size(); i++) {
                int neighbor = graph[node][i];
                if (color[neighbor] == -1) {
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1 && !check(i, graph, color)) {
                return false;
            }
        }
        return true;
    }
};
