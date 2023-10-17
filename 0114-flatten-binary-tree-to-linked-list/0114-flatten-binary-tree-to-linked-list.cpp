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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* rightm = curr->left;
                while(rightm->right){
                    rightm = rightm->right;
                }
                rightm->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
                curr = curr->right;
        }
    }
};