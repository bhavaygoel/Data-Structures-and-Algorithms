//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void helper(stack<int>& s, int middle){
        if(s.size() == 0) return;
        if(s.size() == middle){
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        helper(s, middle);
        s.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here..
        int middle = ceil((sizeOfStack + 1)/2);
        helper(s, middle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends