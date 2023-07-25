class Solution {
public:
    bool isValid(vector<string>& nqueens, int row, int col, int n){
        for(int i=0; i != row; i++){
            if(nqueens[i][col] == 'Q') return false;
        }
         for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nqueens[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nqueens[i][j] == 'Q')
                return false;
        return true;
    }
    void solve(int n, vector<string>& nqueens,int row, int& ans){
        if(row == n){
            ans++;
            return;
        }
        for(int col=0; col != n; col++){
            if(isValid(nqueens, row, col, n)){
                nqueens[row][col] = 'Q';
                solve(n, nqueens, row+1, ans);
                nqueens[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> nqueens(n, string(n, '.'));
        int ans=0;
        solve(n, nqueens,0,  ans);
        return ans;
    }
};