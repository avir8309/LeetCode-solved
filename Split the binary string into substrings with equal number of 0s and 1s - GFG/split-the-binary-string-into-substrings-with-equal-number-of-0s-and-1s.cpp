//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        int cnt0=0;
        int cnt1=0;
        int ans=0;
        int n=str.length();
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                cnt0++;
            }
            else{
                cnt1++;
            }
            if(cnt0==cnt1){
                ans++;
                cnt0=0;
                cnt1=0;
            }
        }
        if(cnt0!=cnt1){
            return -1;
        }
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
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends