//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int n) {
        // code here
        vector<int> nextgreater;
        stack<int> st;
        st.push(n-1);
        nextgreater.push_back(-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and arr[st.top()]<arr[i]){
                st.pop();
            }
            if(st.empty()){
                nextgreater.push_back(-1);
            }
            else{
                nextgreater.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nextgreater.begin(),nextgreater.end());
        vector<int> pre(n);
        pre[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            pre[i]=min(pre[i+1],arr[i]);
        }
        //last waala banda ya -1 to continue;
        for(int i=0;i<n;i++){
            int a=nextgreater[i];
            if(a==-1 or a==n-1){
                continue;
            }
            if(pre[a+1]<arr[i]){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends