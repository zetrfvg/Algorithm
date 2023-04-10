/*
不失一般性
假设考虑把1放在位置x上，那么接下来考虑x该怎么放
如果把x放在位置1上，那么就解决了x和1两个数该怎么放，剩下只需要对其他n-2个数进行错位排列即可
如果把x放在除1以外的位置上，此时把x视为1，因为他不能放在位置1上，于是就转化为对除1以外剩下的n-1个数进行错位排列

状态定义：
dp[i]：i个数的错位排列方案
转移方程：
dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
*/
class Solution {
public:
    int findDerangement(int n) {
        const int mod=1e9+7;
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=2;i<=n;i++){
            dp[i]=1LL*(i-1)*(dp[i-1]+dp[i-2])%mod;
        }
        return dp[n];
    }
};
