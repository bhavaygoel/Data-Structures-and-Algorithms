class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> t(n + 1, -1);
        for(int i=0; i<3; i++){
            t[i] = i;
        }
        for(int i=3; i<n+1; i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};