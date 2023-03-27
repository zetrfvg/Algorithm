/*
状态定义：
dp1[i][j]：当s的第i个字符和t的第j个字符不同时，它们左侧连续的相等的字符最多有多少个
dp2[i][j]：当s的第i个字符和t的第j个字符不同时，它们又侧连续的相等的字符最多有多少个
则以s[i]、t[j]作为子串中需要被替换的字符时，它们的贡献是(dp1[i][j]+1)*(dp2[i+1][j+1]+1)
转移方程：
dp1[i][j]=s[i-1]==t[j-1]?dp1[i-1][j-1]+1:0;
dp2[i][j]=s[i]==t[j]?dp2[i+1][j+1]+1:0;
*/
class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp1(n+1,vector<int>(m+1)),dp2(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp1[i][j]=s[i-1]==t[j-1]?dp1[i-1][j-1]+1:0;
            }
        }
        for(int i=n-1;~i;i--){
            for(int j=m-1;~j;j--){
                dp2[i][j]=s[i]==t[j]?dp2[i+1][j+1]+1:0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]!=t[j]){
                    ans+=(dp1[i][j]+1)*(dp2[i+1][j+1]+1);
                }
            }
        }
        return ans;
    }
};
