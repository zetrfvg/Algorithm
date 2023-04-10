/*
如果使用复制粘贴，则一直使用粘贴操作到最后一步一定最优
状态定义：
dp[i]：i次操作后A的最大数量
转移方程：
dp[i]=max(dp[i-1]+1,max(dp[j-2]*(i-j+1)))
*/
class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]+1;
            for(int j=2;j<i;j++){
                dp[i]=max(dp[i],dp[j-2]*(i-j+1));
            }
        }
        return dp[n];
    }
};
