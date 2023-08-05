//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i=0,j=0, n=s.size();
        int ans = INT_MIN;
        unordered_map<int, int> m;
        while(j < n){
            m[s[j]]++;
            if(m.size() == k){
                ans = max(ans, j-i+1);
            }
            while(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] <= 0){
                    m.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return ans == INT_MIN ? -1 : ans ;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends