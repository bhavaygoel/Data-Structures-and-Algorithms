class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0, n=fruits.size(), count=0;
        int ans = INT_MIN;
        unordered_map<int, int> m;
        while(j < n){
            m[fruits[j]]++;
            if(m[fruits[j]] == 1){
                count++;
            }
            if(count <= 2){
                ans = max(ans, j-i+1);
            }
            while(count > 2){
                m[fruits[i]]--;
                if(m[fruits[i]] == 0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return ans == INT_MIN ? 1 : ans;
    }
};