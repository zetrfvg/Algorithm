/*
定义状态：
dp[i][0]：以第i个元素结尾，且最后两项之差为正数的摆动序列的最长长度
dp[i][1]：以第i个元素结尾，且最后两项之差为负数的摆动序列的最长长度
转移方程：
if(nums[i]>nums[j]) dp[i][0]=max(dp[i][0],dp[j][1]+1);
if(nums[i]<nums[j]) dp[i][1]=max(dp[i][1],dp[j][0]+1);
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i][0]=dp[i][1]=1;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i][0]=max(dp[i][0],dp[j][1]+1);
                if(nums[i]<nums[j]) dp[i][1]=max(dp[i][1],dp[j][0]+1);
            }
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};

/*
优化
定义状态：
dp[i][0]：前i个元素组成的序列中，最后两项之差为正数的摆动序列的最长长度
dp[i][1]：前i个元素组成的序列中，最后两项之差为负数的摆动序列的最长长度
转移方程：
 if(nums[i]>nums[i-1]){
    dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
    dp[i][1]=dp[i-1][1];
}else if(nums[i]<nums[i-1]){
    dp[i][1]=max(dp[i-1][1],dp[i-1][0]+1);
    dp[i][0]=dp[i-1][0];
}else{
    dp[i][0]=dp[i-1][0];
    dp[i][1]=dp[i-1][1];
}
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0]=dp[0][1]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
                dp[i][1]=dp[i-1][1];
            }else if(nums[i]<nums[i-1]){
                dp[i][1]=max(dp[i-1][1],dp[i-1][0]+1);
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};
