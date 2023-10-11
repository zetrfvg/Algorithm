/*
把所有不相等的位置存入到一个p数组中
操作一：
修改s[i]，花费相当于x/2，注意这个转移一定会发生偶数次，因为 ppp 的长度是偶数，并且第二种操作每次反转两个数，所以第一种操作一定会反转偶数个下标
操作二；
修改相邻的两个位置，花费为p[i]-p[i-1]
状态定义：
dp[i]：修改前i个位置的最小代价
转移方程：
dp[i]=min(dp[i-1]+x,dp[i-2]+(p[i-1]-p[i-2])*2);
*/
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int> p;
        for(int i=0;i<n;i++) if(s1[i]!=s2[i]) p.push_back(i);
        if(p.size()&1) return -1;
        if(!p.size()) return 0;
        vector<int> dp(p.size()+1);
        dp[1]=x;
        for(int i=2;i<=p.size();i++){
            dp[i]=min(dp[i-1]+x,dp[i-2]+(p[i-1]-p[i-2])*2);
        }
        return dp.back()/2;
    }
};
