/*
状态定义：
dp[i]：前i的字符组成的字串能否被wordDict中的字符串拼接表示
状态转移：
对于dp[i]，我们枚举它之前的所有dp[j]状态
如果dp[j]能被wordDict中的字符串拼接表示，且从j到i的字符组成的串也能被表示则dp[i]可被表示

时间复杂度：O(n^2)
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(auto t:wordDict) st.insert(t);
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;~j;j--){
                if(dp[j]&&st.count(s.substr(j,i-j))){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
