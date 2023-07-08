class Solution {
public:
    bool isValid(vector<int>& weights, int days, int maxi){
        int day = 1, sum =0;
        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            if(sum > maxi){
                day++;
                sum = weights[i];
            }
            if(day > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start=*max_element(weights.begin(), weights.end());
        if(days == weights.size()) return start;
        int end=0;
        for(auto& it: weights){
            end += it;
        }
        int ans = -1;
        while(start <= end){
            int mid = start + (end- start)/2;
            if(isValid(weights, days, mid)){
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