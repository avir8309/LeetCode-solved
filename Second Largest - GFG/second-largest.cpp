//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,arr[i]);
	    }
	    int secondsmallest=INT_MIN;
	    for(int i=0;i<n;i++){
	        if(secondsmallest<maxi and arr[i]!=maxi){
	            secondsmallest=max(secondsmallest,arr[i]);
	            
	        }
	    }
	    return secondsmallest==INT_MIN ? -1 : secondsmallest;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends