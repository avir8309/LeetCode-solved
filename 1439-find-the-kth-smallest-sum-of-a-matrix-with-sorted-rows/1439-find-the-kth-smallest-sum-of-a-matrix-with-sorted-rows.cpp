typedef pair<int,set<pair<int,int>>> pi;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        int n=mat.size();
        int m=mat[0].size();
        set<pair<int,int>> st;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=mat[i][0];
            st.insert({i,0});

        }
        pq.push({sum,st});
        int ans=-1;
        set<set<pair<int,int>>>vis;
        vis.insert(st);
        while(!pq.empty() and k--){
            auto x=pq.top();
            pq.pop();
            ans=x.first;
            auto p=x.second;
            //extract top element
            //go in its set
            //and check for evry coordinate that can we increment it
            for(auto z: x.second){
                set<pair<int,int>>p=x.second;
                p.erase(z);
                int i=z.first;
                int j=z.second;
                p.insert({i,j+1});
                if(j+1<m and vis.find(p)==vis.end()){
                    pq.push({ans-mat[i][j]+mat[i][j+1],p});
                    vis.insert(p);
                }

            }



        }
        return ans;

        
    }
};