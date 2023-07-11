class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(int& it: nums){
            totalSum += it;
        }
        if(totalSum %2 != 0) return false;
        int sum = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> t(n+1,vector<bool>(sum+1, false));
        for(int j=0; j<sum+1; j++) t[0][j] = false;
        for(int i=0; i<n+1; i++) t[i][0] = true;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
};