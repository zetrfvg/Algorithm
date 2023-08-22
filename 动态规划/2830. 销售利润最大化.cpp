/*
状态定义：
dp[i]：销售前i个房子能获得的最大利润
对offers按右端点排序，右端点相同的归为一组处理进行状态转移
转移方程：
对于枚举到的offers[i]=[l,r,w]，dp[i]=max(dp[i-1],dp[l-1]+w)
*/
class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(n+1,0);
        int m=offers.size();
        sort(offers.begin(),offers.end(),[](const auto& a,const auto& b){
            return a[1]<b[1];
        });
        int ans=0;
        for(int i=1,j=0;i<=n;i++){
            dp[i]=dp[i-1];
            while(j<m&&offers[j][1]+1==i){
                int l=offers[j][0]+1,r=offers[j][1]+1,w=offers[j][2];
                dp[i]=max(dp[i],dp[l-1]+w);
                j++;
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
