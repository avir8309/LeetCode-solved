//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#define ll long long
class Solution{
  public:
    long long findRank(string str) {
        //code here
        //will create a hashset to store words
        ll ans=0;
        ll fact[19];
        fact[0]=1;
        for(int i=1;i<=18;i++){
            fact[i]=i*fact[i-1];
        }
        set<char> st;
        for(auto x: str){
            st.insert(x);
            
        }
        ll n=str.size();
        //bande p[e jaunfga chhote words calculate karunga or n-1-i fact se multiply karunga]
        ll i=0;
        for(auto x: str){
            ll cnt=0;
            for(auto p: st){
                if(p<x){
                    cnt++;
                }
            }
            st.erase(x);
            ans+=(cnt)*fact[n-i-1];
            i++;
        }
        return ans+1;
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends