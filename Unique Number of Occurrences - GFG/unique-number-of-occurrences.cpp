//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_set<int> s;
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            if(m.find(arr[i]) == m.end()){
                m[arr[i]] == 1;
                continue;
            }
            m[arr[i]]++;
        }
        for(auto& it:m){
            s.insert(it.second);
        }
        if(s.size() == m.size()) return true;
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends