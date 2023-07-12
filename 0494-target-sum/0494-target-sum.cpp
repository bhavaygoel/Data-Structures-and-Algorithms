class Solution {
public:
    void helper(vector<int>& nums, int target, int& ans, int curr, int index){
        if(index >= nums.size()) {
            if(curr == target){
                ans++;
            }
            return;
        }
        int val = nums[index];
        helper(nums, target, ans, curr+val, index+1);
        helper(nums, target, ans, curr-val, index+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        helper(nums, target, ans, 0, 0);
        return ans;
    }
};