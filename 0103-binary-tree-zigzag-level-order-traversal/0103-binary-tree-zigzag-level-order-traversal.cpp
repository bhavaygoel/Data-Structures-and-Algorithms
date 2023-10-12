/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        bool isLtR = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                if(isLtR){
                    TreeNode* temp = q.front();
                    q.pop_front();
                    int index = isLtR ? i : size-i-1;
                    level.push_back(temp->val);
                    if(temp->left)
                        q.push_back(temp->left);
                    if(temp->right)
                        q.push_back(temp->right);
                }
                else{
                    TreeNode* temp = q.back();
                    q.pop_back();
                    level.push_back(temp->val);
                    if(temp->right)
                        q.push_front(temp->right);
                    if(temp->left)
                        q.push_front(temp->left);
                }
            }  
            isLtR = !isLtR;
            ans.push_back(level);
        }
        return ans;
    }
};