class Solution {
public:
    int t[2501][2501];
    int helper(vector<int>& nums,int prev,  int index){
        if(index <= 0){
            return 0;
        }
        if(t[index][prev] != -1) return t[index][prev];
        if(prev == nums.size() || nums[index-1] < nums[prev]){
            t[index][prev] = max(helper(nums, prev, index-1), 1 + 
                                helper(nums, index-1, index-1));
        }
        else{
           t[index][prev] = helper(nums, prev, index-1);
        }
        return t[index][prev];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return helper(nums, n, n);
    }
};