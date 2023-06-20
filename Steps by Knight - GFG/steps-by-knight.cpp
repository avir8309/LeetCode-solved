//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    
    int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        int sx = knightPos[0];
        int sy = knightPos[1];
        int ex = targetPos[0];
        int ey = targetPos[1];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        queue<pair<int, int>> q;

        dp[sx][sy] = 0;
        q.push({sx, sy});

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == ex && y == ey) {
                return dp[x][y];
            }

            for (int i = 0; i < 8; i++) {
                int newx = x + dx[i];
                int newy = y + dy[i];

                if (newx >= 1 && newx <= n && newy >= 1 && newy <= n && dp[newx][newy] == INT_MAX) {
                    dp[newx][newy] = dp[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }

        return -1; // Target position cannot be reached
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends