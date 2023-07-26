class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=nums.size()-1, count=0;
        while(i < nums.size() && i <= j){
            if(nums[i] == val){
                swap(nums[i], nums[j]);
                count++;
                j--;
                continue;
            }
            i++;
        }
        return nums.size() - count;
    }
};