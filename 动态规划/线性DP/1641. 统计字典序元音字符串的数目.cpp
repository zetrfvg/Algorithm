/*
状态定义：
dp[i][j]：长度为i的串，最后一个字符为j的字符串数量
转移方程：
dp[i][j]=Σdp[i-1][k]，j∈[0,j]
*/
class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n,vector<int>(5));
        for(int i=0;i<5;i++) dp[0][i]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<5;j++){
                for(int u=0;u<=j;u++){
                    dp[i][j]+=dp[i-1][u];
                }
            }
        }
        return accumulate(dp.back().begin(),dp.back().end(),0);
    }
};
