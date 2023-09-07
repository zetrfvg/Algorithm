/*
预处理，然后简单递推
*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> row(n),col(m);
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    row[i]++,col[j]++;
                    dp[0][0]+=i+j;
                }
            }
        }
        for(int i=1;i<n;i++) row[i]+=row[i-1];
        for(int i=1;i<m;i++) col[i]+=col[i-1];
        for(int i=1;i<n;i++) dp[i][0]=dp[i-1][0]-row[n-1]+2*row[i-1];
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i][j-1]-col[m-1]+2*col[j-1];
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
                ans=min(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
