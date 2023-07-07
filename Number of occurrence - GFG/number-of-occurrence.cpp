//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int binaryS(int nums[],int n, int target, bool start){
        int s=0, e= n-1, mid, ans = -1;
        while(s<= e){
            mid = s + (e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                if(start){
                    e = mid-1;
                }
                else s = mid+1;
            }
            else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
	int count(int nums[], int n, int x) {
	    int end = -1, start = -1;
        start = binaryS(nums,n,  x, true);
        if(start != -1) end = binaryS(nums, n, x, false);
        else return 0;
        return end - start + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends