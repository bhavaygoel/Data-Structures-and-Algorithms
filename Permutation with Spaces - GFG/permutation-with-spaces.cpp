//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    void helper(string p, string up, vector<string>& ans){
        if(up.size() == 0){
            ans.push_back(p);
            return;
        }
        helper(p+" "+up[0],up.substr(1), ans);
        helper(p+up[0], up.substr(1), ans);
        
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string> ans;
        string p = string(1, S[0]);
        helper(p, S.substr(1), ans);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends