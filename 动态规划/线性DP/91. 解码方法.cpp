/*
状态定义：
dp[i]：表示前i个字符的解码方法数量
转移方程：
考虑第i个字符，如果只使用一个字符进行解码，有：
dp[i]+=dp[i-1]
要注意，该字符不能为0.
如果使用两个字符进行解码，有：
dp[i]+=dp[i-2]
要注意需满足i>1，且两字符加起来需要小于26
*/
class Solution {
public:
    int numDecodings(string s) {
        int ans=0;
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            if(i>1&&s[i-2]!='0'&&((s[i-2]-'0')*10+(s[i-1]-'0')<=26)){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
