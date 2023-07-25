class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int currMax=1, currMin=1, temp=1;
        for(auto i: nums){
            temp = currMax;
            currMax = max({currMax* i, currMin*i, i});
            currMin = min({temp * i, currMin* i, i});
            ans = max(ans, currMax);
        }
        return ans;
    }
};