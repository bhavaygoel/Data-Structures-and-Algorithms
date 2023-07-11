class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(ans,s,n,n, n);
        return ans;
    }
    void helper(vector<string>& ans, string& s, int left, int right, int n){
        if(left == 0 && right ==0){
            ans.push_back(s);
            return;
        }
        if(left > 0){
            s += '(';
            helper(ans,s,left-1,right,n);
            s.pop_back();
        }
        if(left < right){
            s += ')';
            helper(ans,s,left,right-1,n);
            s.pop_back();
        }
    }
};