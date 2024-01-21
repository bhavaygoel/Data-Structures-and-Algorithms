class Solution {
public:
    int helper(vector<int>& nums, int maxi, int index, int t[]){
        if(index < 0){
            return 0;
        }
        if(t[index] != -1)
            return t[index];
        int take = nums[index] + helper(nums, maxi, index-2, t);
        int leave = helper(nums, maxi, index-1, t);
        maxi = max(take, leave);
        return t[index] = maxi;
    }
    int rob(vector<int>& nums) {
        int index= nums.size()-1;
        int t[index+2];
        memset(t, -1, sizeof(t));
        return helper(nums, INT_MIN, index, t);
    }
};