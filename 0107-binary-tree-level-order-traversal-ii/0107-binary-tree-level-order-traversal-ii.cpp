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
    int height(TreeNode* root){
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
    void helper(TreeNode* root, int level, vector<vector<int>>& ans){
        if(!root) return;
        ans[level].push_back(root->val);
        helper(root->left, level-1, ans);
        helper(root->right, level-1, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        int level = height(root);
        vector<vector<int>> ans(level);
        helper(root,level-1, ans);
        return ans;
    }
};