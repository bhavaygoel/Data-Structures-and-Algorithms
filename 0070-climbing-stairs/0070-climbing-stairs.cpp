class Solution {
public:
    int helper(int n, vector<int>& t){
        if(n <= 2)
            return n;
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