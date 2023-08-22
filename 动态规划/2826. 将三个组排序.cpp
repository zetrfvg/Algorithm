/*
题意转换：经若干次操作将数组变为[1……1,2……2,3……3]
状态定义：
dp[i][j]：考虑前i个元素，将第i个元素变为第j组的元素的最小操作数
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(3,1e9));
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                dp[i+1][0]=dp[i][0];
                dp[i+1][1]=min(dp[i][0],dp[i][1])+1;
                dp[i+1][2]=min({dp[i][0],dp[i][1],dp[i][2]})+1;
            }else if(nums[i]==2){
                dp[i+1][0]=dp[i][0]+1;
                dp[i+1][1]=min(dp[i][0],dp[i][1]);
                dp[i+1][2]=min({dp[i][0],dp[i][1],dp[i][2]})+1;
            }else{
                dp[i+1][0]=dp[i][0]+1;
                dp[i+1][1]=min(dp[i][0],dp[i][1])+1;
                dp[i+1][2]=min({dp[i][0],dp[i][1],dp[i][2]});
            }
        }
        return min({dp[n][0],dp[n][1],dp[n][2]});
    }
};
