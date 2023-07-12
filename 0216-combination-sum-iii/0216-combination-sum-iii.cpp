class Solution {
public:
    void helper(int i, int n, int k, vector<int>& set, vector<vector<int>>& ans){
        if(n == 0 && k == 0){
            ans.push_back(set);
            return;
        }
        if(n <= 0 || k <= 0 || i == 10){
            return;
        }
        helper(i+1,n,k,set,ans);
        set.push_back(i);
        helper(i+1, n-i, k-1, set, ans);
        set.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> set;
        helper(1,n,k,set,ans);
        return ans;
    }
};