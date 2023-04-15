/*
预处理：把每个人可以戴哪些帽子转化为每个帽子可以被哪些人来戴
状态定义：
dp[i][st]：考虑前i个帽子，st表示哪些人戴了帽子，如st=7，其二进制表示为0111，代表第1、2、3个人戴了帽子
转移方程：
if((st>>j)&1){
    dp[i][st]=(dp[i][st]+dp[i-1][st^(1<<j)])%mod;
}
*/
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        const int mod=1e9+7;
        int n=hats.size();
        int mx=0;
        for(auto &h:hats){
            for(int &c:h){
                mx=max(mx,c);
            }
        }
        vector<vector<int>> hat(mx+1);
        for(int i=0;i<n;i++){
            for(auto &c:hats[i]){
                hat[c].push_back(i);
            }
        }
        int dp[mx+1][1<<n];
        memset(dp,0,sizeof dp);
        dp[0][0]=1;
        for(int i=1;i<=mx;i++){
            for(int st=0;st<(1<<n);st++){
                dp[i][st]=dp[i-1][st];
                for(auto j:hat[i]){
                    if((st>>j)&1){
                        dp[i][st]=(dp[i][st]+dp[i-1][st^(1<<j)])%mod;
                    }
                }
            }
        }
        return dp[mx][(1<<n)-1];
    }
};
