class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int start=0,end=0;
        int ans=0;
        vector<int> abc(3,0);
        while(end < n){
            abc[s[end] - 'a']++;
            while(abc[0] >= 1 && abc[1] >= 1 && abc[2] >= 1){
                ans += n-end;
                abc[s[start] - 'a']--;
                start++;
            }
            end++;
        }
        return ans;
    }
};