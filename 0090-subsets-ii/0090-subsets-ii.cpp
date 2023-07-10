class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtrack(0, nums, subset, res);
        return res;
    }

private:
    void backtrack(int i, const vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        
        subset.push_back(nums[i]);
        backtrack(i + 1, nums, subset, res);
        subset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(i + 1, nums, subset, res);
    }
};
