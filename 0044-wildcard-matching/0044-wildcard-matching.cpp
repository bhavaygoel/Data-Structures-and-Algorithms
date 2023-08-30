class Solution {
public:
    int t[2001][2001];
    bool isAllstar(string& s, int i){
        for(int j=i; j>=0; j--){
            if(s[j] != '*')
                return false;
        }
        return true;
    }
    bool helper(string& s, string& p, int i, int j){
        if(i<0 && j<0) return 1;
        if(i<0 && j >= 0) return isAllstar(p,j);
        if(j<0 && i>=0) return 0;
        if(t[i][j] != -1) return t[i][j];
        if(s[i] == p[j] || p[j] == '?'){
            return t[i][j] = helper(s,p,i-1,j-1);
        }
        else if(p[j] =='*'){
            return t[i][j] = (helper(s,p,i,j-1) || helper(s,p,i-1,j));
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        memset(t, -1, sizeof(t));
        return helper(s,p,n-1,m-1);
    }
};