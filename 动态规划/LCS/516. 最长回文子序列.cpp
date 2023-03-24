/*
状态定义：
dp[i][j]：区间[j,i]的最长回文子序列的长度
转移方程：
if(s[i]==s[j]){
    dp[i][j]=dp[i-1][j+1]+2;
}else{
    dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
}
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            for(int j=i-1;j>=0;j--){
                if(s[i]==s[j]){
                    dp[i][j]=dp[i-1][j+1]+2;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j+1]);
                }
            }
        }
        return dp[n-1][0];
    }
};
