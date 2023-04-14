/*
状态定义：
dp[c][l][r]：区间[l,r]中以字符c作为两端字符的回文子序列的最长长度
转移方程：
因为长度为偶数，首先预处理出所有dp[c][l][r]，满足s[l]==s[r]且r=l+1
然后dp，当前枚举区间[l,r]
如果两端点的字符等于x，则从dp[y][l+1][r-1]中找一个最大值，y为任意小写字母，转移方程为：
dp[x][l][r]=max(dp[y][l+1][r-1]+2)
如果两端点的字符不相等，则转移方程为：
dp[x][l][r]=max({dp[x][l][r],dp[x][l+1][r],dp[x][l][r-1]})
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[26][n][n];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]) dp[s[i]-'a'][i][i+1]=2;
        }
        for(int len=3;len<=n;len++){
            for(int l=0,r=len-1;r<n;l++,r++){
                for(int x=0;x<26;x++){
                    if(s[l]==s[r]&&s[l]=='a'+x){
                        for(int y=0;y<26;y++){
                            if(x==y) continue;
                            dp[x][l][r]=max(dp[x][l][r],dp[y][l+1][r-1]+2);
                        }
                    }else{
                        dp[x][l][r]=max({dp[x][l][r],dp[x][l+1][r],dp[x][l][r-1]});
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=max(ans,dp[i][0][n-1]);
        }
        return ans;
    }
};
