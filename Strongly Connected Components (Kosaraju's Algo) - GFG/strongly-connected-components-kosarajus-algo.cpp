//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph
	void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
	    vis[node]=1;
	    for(auto x: adj[node]){
	        if(!vis[x]){
	            dfs(x,vis,st,adj);
	            
	        }
	    }
	    st.push(node);
	    
	}
	void dfs2(int node,vector<int>&vis,vector<int>adj[]){
	    vis[node]=1;
	    for(auto x: adj[node]){
	        if(!vis[x]){
	            dfs2(x,vis,adj);
	            
	        }
	    }
	    
	}
    int kosaraju(int n, vector<vector<int>>& adj)
    {
        //code here
        stack<int> st;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        vector<int>adjt[n];
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                adjt[x].push_back(i);
            }
        }
        int scc=0;
        vector<int> vis2(n,0);
        while(!st.empty()){
            auto x=st.top();
            st.pop();
            if(!vis2[x]){
                scc++;
                dfs2(x,vis2,adjt);
            }
        }
        return scc;
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends