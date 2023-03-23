/*
正难则反
考虑问题向LCS转化，因为要求删除的字符ASCII值之和最小
因此相当于我们希望求一个ASCII值之和最大的LCS序列
定义状态：
dp[i][j]：考虑s1的前i个字符和s2的前j个字符中ASCII值之和最大的LCS
转移方程：
dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
if(s1[i-1]==s2[j-1]){
    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+s1[i-1]);
}
*/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+s1[i-1]);
                }
            }
        }
        int sum=0;
        for(auto c:s1) sum+=c;
        for(auto c:s2) sum+=c;
        return sum-2*dp[n][m];
    }
};
