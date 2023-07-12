//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    
    long long modPow(long long n, long long r, long long MOD){
        long long result = 1;
        n = n % MOD;
        while(r > 0){
            if(r%2 == 1){
                result = (result * n) % MOD;
            }
            
            r = r>>1;
            n = (n * n )% MOD;
        }
        return result;
    }
    
    long long power(int N,int R)
    {
       //Your code here
       long long MOD = 1e9 + 7;
       long long n = (long long)N;
       long long r = (long long)R;
       long long ans = modPow(n,r,MOD);
       return ans;
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends