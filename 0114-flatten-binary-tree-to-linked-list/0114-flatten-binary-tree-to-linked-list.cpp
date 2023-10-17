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
    void helper(TreeNode* root, queue<TreeNode*>& q){
        if(root == NULL) return;
        q.push(root);
        helper(root->left, q);
        helper(root->right, q);
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        queue<TreeNode*> q;
        helper(root, q);
        TreeNode* temp = NULL;
        while(!q.empty()){
            if(temp){
                temp->right = q.front();
                temp->left = NULL;
                temp = temp->right;
            }
            else
                temp = q.front();
            q.pop();
        }
    }
};