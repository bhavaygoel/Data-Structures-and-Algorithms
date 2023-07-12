class Solution {
public:
    int helper(vector<int>& nums, int target, int curr, int index, vector<vector<int>>& t, int total){
        if(index >= nums.size()) {
            if(curr == target){
                return 1;
            }
            return 0;
        }
        if(t[index][total + curr] != -1){
            return t[index][total + curr];
        }
        int val = nums[index];
       t[index][total+curr] =  helper(nums, target, curr+val, index+1, t, total)+ helper(nums, target, curr-val, index+1, t, total);
        return t[index][total+curr];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(auto& it: nums){
            total += it;
        }
        vector<vector<int>> t(nums.size()+1, vector<int>(2*total+1, -1));
        return helper(nums, target, 0, 0, t, total);

    }
};