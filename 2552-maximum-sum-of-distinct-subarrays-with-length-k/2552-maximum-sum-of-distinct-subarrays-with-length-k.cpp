class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i=0, j=0, n=nums.size();
        long long sum=0, ans=-1;
        unordered_map<long, int> m;
        while(j < n){
            sum += nums[j];
            m[nums[j]]++;
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(m.size() == k) 
                    ans = max(ans, sum);
                sum -= nums[i];
                if(!(--m[nums[i]])) 
                    m.erase(nums[i]);
                i++;j++;
            }
        }
        return ans == -1 ? 0 : ans;
    }
};