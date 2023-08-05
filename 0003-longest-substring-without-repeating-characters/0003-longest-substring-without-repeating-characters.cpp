class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.size(), count = 0;
        int ans = INT_MIN;
        unordered_map<int, int> m;
        while(j < n){
            m[s[j]]++;
            if(j-i+1 == m.size()){
                ans = max(ans, j-i+1);
            }
            while(j-i+1 > m.size()){
                m[s[i]]--;
                if(m[s[i]] == 0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans == INT_MIN ? 0 : ans;
    }
};