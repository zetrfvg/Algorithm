/*
预处理出所有5的幂
状态定义：
dp[i]：考虑第i个以后的元素，能够分割的最少子串个数
转移方程：
dp[i]=min(dp[i],dp[j+1]+1)，其中[i,j]组成的十进制数需要是5的幂
*/
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        int ans=1e9;
        unordered_set<int> st{1,5,25,125,625,3125,15625,78125};
        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;~i;i--){
            if(s[i]!='0'){
                int num=0;
                for(int j=i;j<n;j++){
                    num=num*2+s[j]-'0';
                    if(st.count(num)) dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
        }
        return dp[0]==1e9?-1:dp[0];
    }
};
