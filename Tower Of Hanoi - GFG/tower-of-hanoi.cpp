//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void helper(int N, int from, int to, int aux, long long& ans){
        ans++;
        if(N == 1){
            cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
            return;
        }
        helper(N-1, from, aux, to, ans);
        cout << "move disk " << N << " from rod " << from << " to rod " << to << endl;
        helper(N-1, aux, to, from, ans);
    }
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long ans=0;
        helper(N, from, to, aux, ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends