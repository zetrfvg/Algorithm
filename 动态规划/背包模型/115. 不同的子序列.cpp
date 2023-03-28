/*
状态定义：
dp[i][j]：s的前i个字符中，与t的前j个字符相同的子序列数量
转移方程：
不让s[i]参与匹配，dp[i][j]由dp[i-1][j]转移而来
让s[i]参与匹配，此时要有s[i]=t[j]，dp[i][j]由dp[i-1][j-1]转移而来
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        if(n<m) return 0;
        vector<vector<unsigned long long>> dp(n+1,vector<unsigned long long>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
