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
        if(t[n][sum] != -1) return t[n][sum];
        
        if(arr[n-1] <= sum){
            t[n][sum] = helper(arr, n-1, sum-arr[n-1], t) || helper(arr, n-1, sum, t);
        }
        else 
            t[n][sum] = helper(arr, n-1, sum, t);
        return t[n][sum];
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> t(arr.size()+1, vector<int>(sum+1, -1));
        int n = arr.size();
        // return helper(arr, n, sum, t);
        for(int j=0; j<sum+1; j++) t[0][j] = 0;
        for(int i=0; i< n+1; i++) t[i][0] = 1;
        for(int i=1; i< n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1] <= j){
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
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