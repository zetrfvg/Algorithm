/*
状态定义：
dp[i]表示第i个丑数
转移方程：
初始令三个指针a=b=c=0
在dp[a]*2,dp[b]*3,dp[c]*5三个数中选出最小的数即为第i个丑数
然后判断dp[i]是否和分别和上述三个数相等，若相等则对应的指针后移一位
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,1);
        int a=0,b=0,c=0;
        for(int i=1;i<n;i++){
            dp[i]=min({dp[a]*2,dp[b]*3,dp[c]*5});
            if(dp[i]==dp[a]*2) a++;
            if(dp[i]==dp[b]*3) b++;
            if(dp[i]==dp[c]*5) c++;
        }
        return dp[n-1];
    }
};
