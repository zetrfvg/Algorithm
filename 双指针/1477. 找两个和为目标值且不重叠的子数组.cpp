/*
双指针枚举右端点，dp记录前i个元素中和为target的最短子数组的长度
*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> dp(n+1);
        dp[0]=1e9;
        int cur=0,ans=1e9;
        for(int l=0,r=0;r<n;r++){
            cur+=arr[r];
            while(cur>target) cur-=arr[l++];
            if(cur==target){
                ans=min(ans,dp[l]+r-l+1);
                dp[r+1]=min(dp[r],r-l+1);
            }else{
                dp[r+1]=dp[r];
            }
        }
        return ans==1e9?-1:ans;
    }
};
