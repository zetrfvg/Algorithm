/*
状态定义：
dp[i]：杀死集合为i的怪物的最短用时
转移方程：
dp[i]=min(dp[i^j]+(power[j]+c-1)/c)，j为i中任意怪物的编号，c表示当前杀死的是第几个怪物，(power[j]+c-1)/c表杀死第j个怪物的用时
*/
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        int n=power.size();
        long long dp[1<<n];
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for(int i=0;i<(1<<n);i++){
            int c=__builtin_popcount(i)+1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) continue;
                dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+1LL*(power[j]+c-1)/c);
            }
        }
        return dp[(1<<n)-1];
    }
};
