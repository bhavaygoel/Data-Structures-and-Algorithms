class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (letters.back() <= target) return letters.front();
        int start =0, end = letters.size()-1, mid;
        char ans = letters[0];
        while(start <= end){
            mid = start + (end-start)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};