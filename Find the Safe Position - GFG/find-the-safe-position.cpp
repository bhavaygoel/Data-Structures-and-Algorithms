//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void helper(vector<int>& v, int n, int k, int& ans,int index){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        index = (index + k) % v.size();
        v.erase(v.begin() + index);
        helper(v, n, k, ans, index);
    }
    int safePos(int n, int k) {
        // code here
        k--;
        int ans;
        vector<int> v(n);
        int index = 0;
        for(int i=1; i<=n; i++){
            v[i-1] = i;
        }
        helper(v, n, k, ans, index);
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends