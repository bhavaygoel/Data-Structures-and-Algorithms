//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<int> Kclosest(vector<int>arr, int n, int x, int k) 
    { 
        // Your code goes here 
        priority_queue<pair<int, int>> maxh;
        vector<int> ans(k);
        int j=0;
        for(auto i: arr){
            maxh.push({abs(i-x), i});
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        while(maxh.size() != 0){
            ans[j++] = maxh.top().second;
            maxh.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }  
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n>>x>>k; 
		vector <int> array(n);
		for (int i = 0; i < n; ++i)
			cin>>array[i];
        
        Solution obj;
		vector <int> result = obj.Kclosest(array, n, x, k); 
		for (int i = 0; i < result.size(); ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}

	return 0; 
} 




// } Driver Code Ends