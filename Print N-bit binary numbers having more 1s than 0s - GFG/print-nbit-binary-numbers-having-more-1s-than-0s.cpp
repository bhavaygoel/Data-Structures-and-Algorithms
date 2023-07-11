//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void helper(string& op, int one, int zero, vector<string>& ans, int& N){
        if(N == 0){
            ans.push_back(op);
            return;
        }
        // if(one >= zero){
            op += '1';
            N--;
            helper(op, one+1, zero, ans, N);
            op.pop_back();
            N++;
        // }
        if(zero < one){
            op += '0';
            N--;
            helper(op, one, zero+1, ans, N);
            op.pop_back();
            N++;
        }
        // op.pop_back();
    }
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    int one = 0;
	    int zero = 0;
	    vector<string> ans;
	    string op;
	    helper(op,one,zero,ans, N);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends