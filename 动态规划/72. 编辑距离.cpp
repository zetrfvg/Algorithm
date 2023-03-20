/*
给定两个串A和B
在A中删除一个字符，等价于在B中插入一个字符
由此转换为以下三种操作：
1、在A中插入一个字符
2、在B中插入一个字符
3、修改A的一个字符

状态定义：
dp[i][j]：A的前i个字符与B的前j个字符的编辑距离
转移方程：
考虑A的前i个字符与B的前j个字符的编辑距离为d
那么A的前i个字符与B的前j+1个字符的编辑距离不会超过d+1
同理，A的前i+1个字符与B的前j个字符的编辑距离不会超过d+1
而一旦A的第i+1个字符与B的第j+1个字符相等
则A的前i+1个字符与B的前j+1个字符的编辑距离也为d
于是得到转移方程：
if(word1[i-1]==word2[j-1]){
    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]-1})+1;
}else{
    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
}
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]-1})+1;
                }else{
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
            }
        }
        return dp[n][m];
    }
};
