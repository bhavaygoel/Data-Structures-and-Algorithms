class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        int start=0, len=INT_MAX;
        for(auto it: t){
            m[it]++;
        }
        int i=0,j=0,count=m.size(),n=s.size();
        while(j < n){
            if(m.find(s[j]) != m.end()){
                m[s[j]]--;
                if(m[s[j]] == 0){
                    count--;
                }
            }
            while(count == 0){
                if(j-i+1<len){
                    len=j-i+1;
                    start=i;
                }
                if(m.find(s[i]) != m.end()){
                    m[s[i]]++;
                    if(m[s[i]] == 1){
                        count++;
                    }
                    
                }
                i++;
            }
            j++;
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};