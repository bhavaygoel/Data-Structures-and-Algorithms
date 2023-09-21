class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int start=-1,end=-1, n=arr.size();
        int l=0, r=n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == x){
                end = mid;
                l = mid+1;
            }
            else if(arr[mid] < x){
                l = mid+1;
            }
            else
                r = mid-1;
        }
        l=0;
        r=n-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] == x){
                start = mid;
                r = mid-1;
            }
            else if(arr[mid] < x){
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return {start, end};
    }
};