class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto& it: nums){
            sum += it;
        }
        if((sum-target)%2 != 0 || target > sum) return 0;

        int n = nums.size();
        int s2 = (sum - target) / 2;
        vector<vector<int>> t(n+1, vector<int>(s2+1,0));
        t[0][0] = 1;
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s2+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][s2];
    }
};