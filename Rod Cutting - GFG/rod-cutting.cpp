//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int N) {
        vector<int> length(N);
        for(int i=0; i<N; i++){
            length[i] = i+1;
        }
        //code here
        vector<vector<int>> t(N+1, vector<int>(N+1, 0));
        for(int i=1; i<N+1; i++){
            for(int j=1; j<N+1; j++){
                if(length[i-1] <= j){
                    t[i][j] = max(t[i-1][j], price[i-1] + t[i][j-length[i-1]]);
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[N][N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends