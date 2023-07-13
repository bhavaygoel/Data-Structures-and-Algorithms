//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int helper(string& text1, string& text2, int index1, int index2, vector<vector<int>>& t){
        if(index1 < 0 || index2 < 0) return 0;
        if(t[index1][index2] != -1) return t[index1][index2];
        if(text1[index1] == text2[index2]){
            t[index1][index2] = 1 + helper(text1, text2, index1-1, index2-1, t);
        }
        else{
            t[index1][index2] = max(helper(text1, text2, index1, index2-1, t), 
                helper(text1, text2, index1-1, index2, t));
        }
        return t[index1][index2];
    }
    int lcs(int n, int m, string text1, string text2)
    {
        // your code here
        vector<vector<int>> t(text1.size(), vector<int>(text2.size(), -1));
        return helper(text1, text2, text1.size()-1, text2.size()-1, t);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends