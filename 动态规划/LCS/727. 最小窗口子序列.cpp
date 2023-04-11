/*
状态定义：
dp[i][j]：s1的前i个字符组成的子串与s2的前j个字符组成的子串相配的起始位置
转移方程：
if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
else dp[i][j]=dp[i-1][j];
*/
class Solution {
public:
    string minWindow(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int len=0x3f3f3f3f;
        string ans;
        int dp[n+1][m+1];
        memset(dp,0x3f,sizeof dp);
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=dp[i-1][j];
            }
            if(dp[i][m]!=0x3f3f3f3f){
                int cur=i-dp[i][m];
                if(cur<len){
                    len=cur;
                    ans=s1.substr(dp[i][m],cur);
                }
            }
        }
        return ans;
    }
};
