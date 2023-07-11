/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void buildGraph(TreeNode* root, TreeNode* parent, unordered_map<int, vector<int>>& adj) {
        if (!root) return;
        
        if (parent) {
            adj[root->val].push_back(parent->val);
            adj[parent->val].push_back(root->val);
        }
        
        buildGraph(root->left, root, adj);
        buildGraph(root->right, root, adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        unordered_map<int, vector<int>> adj;
        buildGraph(root,NULL, adj);
        queue<int> q;
        unordered_set<int> vis;
        q.push(target->val);
        vis.insert(target->val);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i< size; i++){
                int node = q.front();
                q.pop();
                for(auto it: adj[node]){
                    if(vis.find(it) == vis.end()){
                        vis.insert(it);
                        q.push(it);
                        level.push_back(it);
                    }
                }
            }
            k--;
            if(k == 0){
                return level;
            }
        }
        return {};
    }
};