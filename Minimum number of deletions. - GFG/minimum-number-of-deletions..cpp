//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string str, int n) { 
    //complete the function here 
    string s2 = str;
    reverse(s2.begin(), s2.end());
    int t[n+1][n+1];
    memset(t, 0, sizeof(t));
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(str[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return n-t[n][n];
} 