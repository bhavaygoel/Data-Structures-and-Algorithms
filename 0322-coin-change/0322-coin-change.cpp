class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> t(coins.size()+1, vector<int>(amount+1, 0));
        for(int j=1; j<amount+1; j++){
            t[0][j] = INT_MAX-1;
        }
        for(int i=1; i<coins.size()+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1] <= j){
                    t[i][j] = min((1 + t[i][j-coins[i-1]]), t[i-1][j]);
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[coins.size()][amount] == INT_MAX-1 ? -1 : t[coins.size()][amount];
    }
};