/*
状态定义：
dp[l][r]：区间[l,r]中的最长回文子序列长度
转移方程：
如果l==r，dp[l][r]=1；
如果s[l]==s[r]，那么dp[l][r]=dp[l+1][r-1]+2
如果s[l]!=s[r]，那么dp[l][r]=max(dp[l+1][r],dp[l][r-1])

最长回文子序列长度为dp[0][n-1]，如果k<=n-dp[0][n-1]，则该串必定k回文
*/
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int len=2;len<=n;len++){
            for(int l=0,r=len-1;r<n;l++,r++){
                if(s[l]==s[r]) dp[l][r]=dp[l+1][r-1]+2;
                else dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
            }
        }
        return dp[0][n-1]+k>=n;
    }
};
