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
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        int t[n+1][m+1];
        memset(t, 0, sizeof(t));
        t[0][0] = 1;
        for(int i = 1; i <= m; i++) {
            if(p[i-1] == '*') {
                t[0][i] = t[0][i-1];
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    t[i][j] = t[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    t[i][j] = t[i-1][j] || t[i][j-1];
                }
                else
                    t[i][j] = 0;
            }
        }
        return t[n][m];
    }
};