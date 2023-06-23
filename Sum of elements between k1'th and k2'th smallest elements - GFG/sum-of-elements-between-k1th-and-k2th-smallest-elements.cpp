//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long helper(long long A[], long long k, long long N){
        priority_queue<int> maxh;
        for(long long i=0; i<N; i++){
            maxh.push(A[i]);
            if(maxh.size() > k){
                maxh.pop();
            }
        }
        return maxh.top();
    }
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        // Your code goes here
        long long mini = helper(A, K1, N);
        long long maxi = helper(A, K2, N);
        long long sum =0;
        for(long long i=0; i<N; i++){
            if(A[i] > mini && A[i] < maxi){
                sum += A[i];
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}

// } Driver Code Ends