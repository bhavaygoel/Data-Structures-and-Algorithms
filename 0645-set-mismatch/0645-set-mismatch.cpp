class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        cyclicsort(nums);
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != i+1){
                ans.push_back(nums[i]);
                ans.push_back(i+1);
            }
        }
        return ans;
    }

    void cyclicsort(vector<int> &v){
        int i=0;
        while(i<v.size()){
            int correct = v[i]-1;
            if(v[i] != v[correct]){
                swap(v[i], v[correct]);
            }
            else
                i++;
        }
    }
};