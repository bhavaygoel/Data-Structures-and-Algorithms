class Solution {
public:
    bool isValid(vector<int>& nums, int k, int maxi){
        int sub = 1, sum =0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            if(sum > maxi){
                sub++;
                sum = nums[i];
            }
            if(sub > k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start=*max_element(nums.begin(), nums.end());
        int end=0;
        for(auto& it: nums){
            end += it;
        }
        if(k == 1) return end;
        int ans = -1;
        while(start <= end){
            int mid = start + (end- start)/2;
            if(isValid(nums, k, mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};