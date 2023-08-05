class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, ans=0, n=s.size(), freq=0;
        unordered_map<char,int> m;
        while(j < n){
            m[s[j]]++;
            freq = max(freq, m[s[j]]);
            if(j-i+1 - freq <= k){
                ans = max(ans, j-i+1);
            }
            else{
                m[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};