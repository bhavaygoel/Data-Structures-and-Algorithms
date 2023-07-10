class Solution {
public:
    void subsets(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& ans){
        if(index >= nums.size()){
            ans.push_back(subset);
            return;
        }
        int temp = nums[index];
        subset.push_back(temp);
        subsets(index+1, nums, subset, ans);
        subset.pop_back();
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        subsets(index+1, nums, subset, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        int index=0;
        sort(nums.begin(), nums.end());
        subsets(index, nums, subset, ans);
        return ans;
    }
};