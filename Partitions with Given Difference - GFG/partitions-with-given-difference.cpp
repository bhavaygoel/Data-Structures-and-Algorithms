//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        // Code here
        int MOD = 1e9 + 7;
        int sum=0;
        for(auto& it: arr){
            sum += it;
        }
        if((sum + diff) % 2 != 0) return 0;
        int s = (sum + diff) / 2;
        vector<vector<int>> t(n+1, vector<int>(s+1, 0));
        t[0][0] = 1;
        for(int i=1; i<n+1; i++){
            for(int j=0; j<s+1;j++){
                if(arr[i-1] <= j){
                    t[i][j] = (t[i-1][j-arr[i-1]] + t[i-1][j]) % MOD;
                }
                else t[i][j] = t[i-1][j] % MOD;
            }
        }
        return t[n][s];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends