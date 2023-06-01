/*
状态定义：
dp[i][0]：小于前一个元素的最长湍流子数组
dp[i][1]：大于前一个元素的最长湍流子数组
转移方程：
因为奇偶是交错排列的，如果当前这个数大于前一个数，必然从前一个数小于前前一个数的状态转移而来
if(arr[i-1]>arr[i]) dp[i][0]=dp[i-1][1]+1;
if(arr[i-1]<arr[i]) dp[i][1]=dp[i-1][0]+1;
*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int ans=1;
        vector<vector<int>> dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                dp[i][0]=dp[i-1][1]+1;
            }
            if(arr[i-1]<arr[i]){
                dp[i][1]=dp[i-1][0]+1;
            }
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;
    }
};
