//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int time=0;
    void dfs(int node,int par,vector<int> adj[],int tin[],int low[],vector<int>&vis,vector<int>&mark ){
        vis[node]=1;
        tin[node]=low[node]=time;
        time++;
        int child=0;
        for(auto x: adj[node]){
            if(x==par)continue;
            if(!vis[x]){
                dfs(x,node,adj,tin,low,vis,mark);
                low[node]=min(low[node],low[x]);
                if(low[x]>=tin[node] and par!=-1){
                    mark[node]=1;
                    
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[x]);
            }
            
        }
        if(child>1 and par==-1 ){
            mark[node]=1;
        }
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        int tin[n],low[n];
        vector<int> vis(n,0),mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,adj,tin,low,vis,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends