/*
状态定义：
dp[i][0]表示不偷第i间屋子能获得的最大价值；
dp[i][1]表示偷第i间屋子能获得的最大价值。
转移方程：
1、向后：
dp[i][0]=max(dp[i-1][0],dp[i-1][1])
dp[i][1]=dp[i-1][0]+nums[i]
2、向前：
dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
dp[i][1]=dp[i+1][0]+nums[i];

因为首尾两栋屋子相连，只能选择偷一个。
1、偷第1间屋子，则余下能偷的屋子只能向后偷到第n-1间屋子；
2、偷第2间屋子，则余下能偷的屋子只能向前偷到第2间屋子；
基于此点，一前一后跑两次动态规划算法，二者答案取最大值即可。
*/
class Solution {
public:
    int rob(vector<int>& nums){
        int ans=0;
        int n=nums.size();
        if(n==1) return nums[0];
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0,dp[0][1]=nums[0];
        for(int i=1;i<n-1;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+nums[i];
        }
        ans=max(dp[n-2][0],dp[n-2][1]);
        dp=vector(n,vector<int>(2,0));
        dp[n-1][0]=0,dp[n-1][1]=nums[n-1];
        for(int i=n-2;i;i--){
            dp[i][0]=max(dp[i+1][0],dp[i+1][1]);
            dp[i][1]=dp[i+1][0]+nums[i];
        }
        ans=max({ans,dp[1][0],dp[1][1]});
        return ans;
    }
};
