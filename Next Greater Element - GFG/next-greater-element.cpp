//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long int>s;
        
        vector<long long int>v(n);
        for(int i=n-1;i>=0;--i){
            if(s.empty()){
                v[i]=-1;
                s.push(arr[i]);
            }
            else if(arr[i]<s.top()){
                v[i]=s.top();
                 s.push(arr[i]);
            }
            else if(arr[i]>=s.top()){
                while(!s.empty() and arr[i]>=s.top()){
                    s.pop();
                }
                if(s.empty()){
                    v[i]=-1;
                    s.push(arr[i]);
                }
                else{
                    v[i]=s.top();
                    s.push(arr[i]);
                }
            }
        }
        return v;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends