/*
状态定义：
dp[i][j]：s的前i个字符能否与p的前j个字符匹配
转移方程：
如果s[i]==p[j]或者p[j]=='.'，则可以直接匹配，转移是dp[i][j]|=dp[i-1][j-1];
而如果p[j]=='*'，则分两种情况：
1、我们不用这个星号及前面一个字母进行匹配，转移是dp[i][j]|=dp[i][j-2];
2、用这个组合进行匹配，则需要s[i]==p[j-1]，转移是dp[i][j]|=dp[i-1][j];
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1]=='*'){
                    dp[i][j]|=dp[i][j-2];
                    if(i&&(s[i-1]==p[j-2]||p[j-2]=='.')){
                        dp[i][j]|=dp[i-1][j];
                    }
                }else if(i&&(s[i-1]==p[j-1]||p[j-1]=='.')){
                    dp[i][j]|=dp[i-1][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
