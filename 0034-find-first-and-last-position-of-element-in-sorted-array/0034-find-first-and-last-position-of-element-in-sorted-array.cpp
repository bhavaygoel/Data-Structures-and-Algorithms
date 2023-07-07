class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int end;
        int start = Giveindex(nums, target, true);
        if(start != -1){
            end = Giveindex(nums, target, false);
        }else{
            return {-1, -1};
        }
        return {start, end};
    }

    int Giveindex(vector<int> m, int target, bool(Startingindex)){
        int s=0, ans=-1;
        int e= m.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(target< m[mid]){
                e= mid-1;
            }
            if (target > m[mid]){
                s = mid+1;
            }
            if(target == m[mid]){
                if(Startingindex){
                    e= mid-1;
                    ans = mid;
                }
                else{
                    s = mid+1;
                    ans=mid;
                }
            }
            
        }
        return ans;
    }
};