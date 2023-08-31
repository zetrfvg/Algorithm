/*
状态定义：
dp[i][j]：到达第i行第j格的方案数
按权值从小到大在网格图中递推出所有的dp[i][j]，具体见代码
*/
class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int countPaths(vector<vector<int>>& grid) {
        const int mod=1e9+7;
        int n=grid.size(),m=grid[0].size();
        vector<array<int,3>> e;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                e.push_back({grid[i][j],i,j});
            }
        }
        sort(e.begin(),e.end());
        vector<vector<int>> dp(n,vector<int>(m,1));
        int ans=0;
        for(auto [w,i,j]:e){
            ans=(ans+dp[i][j])%mod;
            for(int k=0;k<4;k++){
                int ii=i+dx[k],jj=j+dy[k];
                if(ii<0||ii>=n||jj<0||jj>=m||grid[ii][jj]<=grid[i][j]) continue;
                dp[ii][jj]=(dp[ii][jj]+dp[i][j])%mod;
            }
        }
        return ans;
    }
};
