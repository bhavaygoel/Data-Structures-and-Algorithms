class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(ans,s,0,0, n);
        return ans;
    }
    void helper(vector<string>& ans, string& s, int left, int right, int n){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(left < n){
            s += '(';
            helper(ans,s,left+1,right,n);
            s.pop_back();
        }
        if(left > right){
            s += ')';
            helper(ans,s,left,right+1,n);
            s.pop_back();
        }
    }
};