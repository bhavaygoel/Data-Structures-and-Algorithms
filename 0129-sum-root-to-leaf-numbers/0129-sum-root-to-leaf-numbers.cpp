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
    void dfs(TreeNode* root,int num, vector<int>& temp){
        num = num*10 + root->val;
        if(!root->left && !root->right){
            temp.push_back(num);
            // num /= 10;
            return;
        }
        if(root->left) dfs(root->left, num, temp);
        if(root->right) dfs(root->right, num, temp);
        num /= 10;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> temp;
        int num=0;
        dfs(root, num, temp);
        int ans=0;
        for(auto& it: temp){
            ans += it;
            cout << it << " ";
        }
        return ans;
    }
};