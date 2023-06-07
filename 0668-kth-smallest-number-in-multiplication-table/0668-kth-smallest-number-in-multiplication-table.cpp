class Solution {
public:
    bool isvalid(int mid,int n,int m,int k){
        int count=0;
        for(int i=1;i<=n;i++){
            count+=min(mid/i , m);
        }
        return count>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int l=1;
        int hi=1e9;
        int ans=hi;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(isvalid(mid,n,m,k)){
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