//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
#define ll long long
class Solution{
  public:
    int largestRectangleArea(vector<int> &nums)
    {
        stack<ll> st;
        //-1 or -1 n*length  -1 or !-1 r*length or !-1 or !-1 r-l-1*n else n-l-1*length
        vector<ll> prevs, nexts;
        
        st.push(0);
        int n = nums.size();
        
        prevs.push_back(-1);
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() and nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                prevs.push_back(-1);
            }
            else
            {
                prevs.push_back(st.top());
            }
            st.push(i);
        }
        
        
        while(!st.empty()){
            st.pop();
        }
        st.push(n-1);
        nexts.push_back(-1);
        for (int i = n-2; i >=0; i--)
        {
            while (!st.empty() and nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nexts.push_back(-1);
            }
            else
            {
                nexts.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nexts.begin(),nexts.end());
      
        ll ans=0;
        for(int i=0;i<n;i++){
            int a=prevs[i];
            int b=nexts[i];
            if(a==-1 and b==-1){
                ans=max(ans,nums[i]*1LL*n);
            }
            else if(a==-1 and b!=-1){
                ans=max(ans,b*1LL*nums[i]);
            }
            else if(a!=-1 and b==-1){
                ans=max(ans,(n-a-1)*1LL*nums[i]);
            }
            else{
                ans=max(ans,(b-a-1)*1LL*nums[i]);
            }
        }
        int m=1e9+7;
        ans=ans%m;
        int a=(int)ans;
        return a;
       

       
        
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>nums(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    nums[j]=0;
                }
                else{
                    nums[j]++;
                }
            }
            ans=max(ans,largestRectangleArea(nums));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends