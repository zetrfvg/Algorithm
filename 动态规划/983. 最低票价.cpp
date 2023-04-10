/*
预处理：
如果买30天的更便宜，那就用30天的价格更新7天的价格
如果买7天的更便宜，那就用7天的价格更新1天的价格 

状态定义：
dp[i]：旅行前i个日子，最小花费
转移方程：
首先令dp[i]=dp[i-1]+cost[0]
记s=days[i]-days[j]+1
如果s<=7，dp[i]=min(dp[i],dp[j-1]+costs[1]);
如果s<=30，dp[i]=min(dp[i],dp[j-1]+costs[2]);
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1);
        costs[1]=min(costs[1],costs[2]);
        costs[0]=min(costs[0],costs[1]);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+costs[0];
            for(int j=i-1;j;j--){
                int s=days[i-1]-days[j-1]+1;
                if(s<=7) dp[i]=min(dp[i],dp[j-1]+costs[1]);
                else if(s<=30) dp[i]=min(dp[i],dp[j-1]+costs[2]);
                else break;
            }
        }
        return dp[n];
    }
};
