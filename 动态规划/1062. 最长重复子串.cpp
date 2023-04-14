/*
状态定义：
dp[i][j]：以第i个字符结尾和以第j个字符结尾的最长重复子串长度
转移方程：
如果s[i]==s[j]，dp[i][j]=dp[i-1][j-1]+1;

dp状态中最大值即为答案
*/
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n=s.size();
        int dp[n+1][n+1],ans=0;
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i-1]==s[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};
