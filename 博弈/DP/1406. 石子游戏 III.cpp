/*
状态定义：
dp[i]：石子堆在区间[i,n]中时，当前决策者能够获得的最多分数
转移方程：
从结果开始向起始状态递推
dp[i]=sum(i,n)-dp[j]，j∈[i+1,i+3]
*/
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        int sum=accumulate(stoneValue.begin(),stoneValue.end(),0);
        vector<int> s(n+1),dp(n+1);
        for(int i=n-1;~i;i--) s[i]=s[i+1]+stoneValue[i];
        for(int i=n-1;~i;i--){
            int x=1e9;
            for(int j=i+1;j<=i+3&&j<=n;j++){
                x=min(x,dp[j]);
            }
            dp[i]=s[i]-x;
        }
        if(dp[0]*2>sum) return "Alice";
        else if(dp[0]*2<sum) return "Bob";
        else return "Tie";
    }
};
