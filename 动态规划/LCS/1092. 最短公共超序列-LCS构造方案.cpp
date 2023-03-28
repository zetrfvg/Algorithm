/*
记str1为s，str2为t
状态定义：
dp[i][j]：考虑s的前i个字符与t的前j个字符组成的超序列的长度
转移方程：
if(str1[i-1]==str2[j-1]){
    dp[i][j]=dp[i-1][j-1]+1;
}else{
    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
}

如何构造答案：
观察转移方程dp[i][j]，如果两个字符相等，则由dp[i-1][j-1]转移而来
否则由dp[i-1][j],dp[i][j-1]二者之一转移而来，且它们转移之间的差值一定是1
于是考虑从最后一个状态向前递推构造答案，用l，r两个指针来从s，t的尾部向前递推
分三种情况：
1、如果当前指向两个字符相等，则加入答案，两个指针都向前移动
2、dp[l][r]由dp[l-1][r]转移而来，即dp[l][r]=dp[l-1][r]+1，则把s[l]加入答案，同时l指针前移
3、dp[l][r]由dp[l][r-1]转移而来，即dp[l][r]=dp[l][r-1]+1，则把t[r]加入答案，同时r指针前移
直到两个指针分别都走完两个字符串为止
因为我们是从后向前递推答案，得到答案的过程是一个逆序的，因此我们需要把答案翻转再返回
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        int l=n,r=m;
        string ans;
        while(l>0&&r>0){
            if(str1[l-1]==str2[r-1]){
                ans+=str1[l-1];
                l--,r--;
            }else if(dp[l][r]==dp[l-1][r]+1){
                ans+=str1[--l];
            }else if(dp[l][r]==dp[l][r-1]+1){
                ans+=str2[--r];
            }
        }
        while(l>0) ans+=str1[--l];
        while(r>0) ans+=str2[--r];
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
