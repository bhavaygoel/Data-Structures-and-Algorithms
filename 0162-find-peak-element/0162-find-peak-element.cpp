class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int start=0, end=nums.size()-1, mid;
        while(start<=end){
            mid = start + (end-start)/2;
            if(mid > 0 && mid < nums.size()-1){
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;
                }
                else if(nums[mid+1] > nums[mid]){
                    start = mid+1;
                }
                else end = mid-1;
            }
            else if(mid == 0){
                if(nums[0] > nums[1])return 0;
                return 1;
            }
            else{
                if(nums[nums.size()-1] > nums[nums.size()-2]) return mid;
                return nums.size()-2;
            }
        }
        return -1;
    }
};