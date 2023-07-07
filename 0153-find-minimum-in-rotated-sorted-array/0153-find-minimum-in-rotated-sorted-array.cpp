class Solution {
public:
    int findMin(vector<int>& nums) {
			int start=0, end = nums.size()- 1, mid, prev;
			if(nums[start] <= nums[end]) return nums[start];
	    while(start <= end){
	      mid = start + (end - start)/2;
	      prev = (mid + nums.size() - 1) % nums.size();
	      if(nums[mid] < nums[prev]){
	        return nums[mid];
	      }
	      else if(nums[mid] >= nums[0]){
	        start = mid +1;
	      }
	      else end = mid-1;
	    }
	    return -1; 
    }
};