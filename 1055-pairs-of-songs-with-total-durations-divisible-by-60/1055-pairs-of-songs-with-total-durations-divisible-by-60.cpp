class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans=0;
        unordered_map<int,int> v;
        for(int i=0; i<n; i++){
          int rem = time[i]%60;
          if(rem == 0)
            ans += v[rem];
          else
            ans += v[60-rem];
          v[rem]++;
        }
        return ans;
    }
};