class Solution {
public:
    int binaryS(vector<int>& nums, int target, bool start){
        int s=0, e= nums.size()-1, mid, ans = -1;
        while(s<= e){
            mid = s + (e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                if(start){
                    e = mid-1;
                }
                else s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int end = -1;
        int start = binaryS(nums, target, true);
        if(start != -1) end = binaryS(nums, target, false);
        return {start, end};
    }
};