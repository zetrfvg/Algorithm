/*
状态定义：
dp[i][j][k]：考虑前i个字符，以字符j开头字符k结尾的串的最长长度
*/
class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& s) {
        int n=s.size();
        int ans=1e9;
        int dp[n][26][26];
        memset(dp,0x3f,sizeof dp);
        dp[0][s[0][0]-'a'][s[0].back()-'a']=s[0].size();
        for(int i=1;i<n;i++){
            int len=s[i].size(),f=s[i].front()-'a',b=s[i].back()-'a';
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if(j==b){
                        dp[i][f][k]=min(dp[i][f][k],dp[i-1][j][k]+len-1);
                    }else{
                        dp[i][f][k]=min(dp[i][f][k],dp[i-1][j][k]+len);
                    }
                    if(f==k){
                        dp[i][j][b]=min(dp[i][j][b],dp[i-1][j][k]+len-1);
                    }else{
                        dp[i][j][b]=min(dp[i][j][b],dp[i-1][j][k]+len);
                    }
                }
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                ans=min(ans,dp[n-1][i][j]);
            }
        }
        return ans;
    }
};
