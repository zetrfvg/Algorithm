/*
状态定义：
dp[i]：前i个字符中用dictionary来覆盖最多能覆盖的字符数量
转移方程：
如果以第i个字符结尾的某个子串能和dictionary中的某个串匹配上，则dp[i]=max(dp[i],dp[j-1]+len)，其中j为子串的左端点，len为子串长度，j∈[0,i]
*/
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int> dp(n+1);
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i];
            for(int j=i,len=1;~j;j--,len++){
                for(auto &t:dictionary){
                    if(t.size()==len&&t==s.substr(j,len)){
                        dp[i+1]=max(dp[i+1],len+dp[j]);
                    }
                }
            }
        }
        return n-dp[n];
    }
};
