class Solution {
public:
    int helper(int n, vector<int>& t){
        if(n <= 0){
            return 0;
        }
        if(n == 2) return 2;
        if(n == 1) return 1;
        if(t[n] != -1){
            return t[n];
        }
        t[n] =  helper(n-1, t) + helper(n-2,t); 
        return t[n];
    }
    int climbStairs(int n) {
        vector<int> t(n + 1, -1);
        return helper(n, t);
    }
};