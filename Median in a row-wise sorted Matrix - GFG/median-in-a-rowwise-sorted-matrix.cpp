//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isvalid(vector<vector<int>>&matrix,int mid,int r,int c){
        int z=r*c /2 + 1;
        int cnt=0;
        for(int i=0;i<r;i++){
            int upper=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            cnt+=upper;
            
        }
        if(cnt>=z){
            return true;
        }
        return false;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here       
        //kind of like binary search on answer +
        int l=0;
        int hi=1e9;
        
        int ans=0;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(isvalid(matrix,mid,R,C)){
                ans=mid;
                hi=mid-1;
                
            }
            else{
                l=mid+1;
                
            }
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends