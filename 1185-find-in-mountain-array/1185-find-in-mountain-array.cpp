/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray& arr) {
        int start = 0, end = arr.length() - 1, mid;

        while (start < end) {
            mid = start + (end - start) / 2;

            if (arr.get(mid) < arr.get(mid + 1))
                start = mid + 1;
            else
                end = mid;
    }

    return start;
}
    int binaryS(MountainArray& arr,int start, int end, int target, bool reversed){
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(arr.get(mid) == target) return mid;
            if(arr.get(mid) < target){
                if(!reversed){
                    start = mid+1;
                }
                else end = mid-1;
            }
            else{
                if(!reversed) end = mid-1;
                else start = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int peak = findpeak(arr);
        if(target == arr.get(peak)) return peak;
        int ans = binaryS(arr,0, peak-1, target, false);
        if(ans != -1) return ans;
        ans = binaryS(arr,peak+1, arr.length()-1, target, true);
        return ans;
    }
};