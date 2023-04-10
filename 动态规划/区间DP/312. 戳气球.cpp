/*
状态定义：
dp[i][j]：把区间（i,j）之内的气球消耗掉能获得的最大价值
转移方程：
dp[i][j]=max(dp[l][k]+dp[k][r]+arr[l]*arr[k]*arr[r])，k为区间(i,j)中的所有点

为了方便处理，在数组的首尾各加上一个1
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        arr.push_back(1);
        for(auto c:nums) arr.push_back(c);
        arr.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2));
        for(int len=3;len<=n+2;len++){
            for(int l=0,r=len-1;l+len-1<=n+1;l++,r++){
                for(int k=l+1;k<r;k++){
                    dp[l][r]=max(dp[l][r],dp[l][k]+dp[k][r]+arr[l]*arr[k]*arr[r]);
                }
            }
        }
        return dp[0][n+1];
    }
};
