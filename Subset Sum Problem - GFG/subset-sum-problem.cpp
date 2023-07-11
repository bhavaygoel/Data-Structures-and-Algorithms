//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool helper(vector<int>& arr, int n, int sum, vector<vector<int>>& t){
        if(sum == 0) return 1;
        if(n <= 0) return 0;
        if(t[n-1][sum] != -1) return t[n-1][sum];
        
        if(arr[n-1] <= sum){
            t[n-1][sum] = helper(arr, n-1, sum-arr[n-1], t) || helper(arr, n-1, sum, t);
        }
        else 
            t[n-1][sum] = helper(arr, n-1, sum, t);
        return t[n-1][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> t(arr.size()+1, vector<int>(sum+1, -1));
        int n = arr.size();
        return helper(arr, n, sum, t);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends