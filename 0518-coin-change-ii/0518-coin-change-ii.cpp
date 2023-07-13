class Solution {
public:
    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& t){
        if(index < 0){
            return 0;
        }
        if(amount == 0) return 1;
        if(t[index][amount] != -1) return t[index][amount];
        if(coins[index] > amount){
            t[index][amount] = helper(index-1, amount, coins, t);
        }
        else {
            t[index][amount] = helper(index-1, amount, coins, t) + 
                                helper(index, amount-coins[index], coins, t);
        }
        return t[index][amount];
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> t(coins.size()+1, vector<int>(amount + 1, -1));
        return helper(coins.size()-1, amount, coins, t);
    }
};