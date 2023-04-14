/*
状态定义：
dp[i]：i表示从nums中选的数的状态，是否可行
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
        sort(nums.begin(),nums.end());
        int n=nums.size(),part=sum/k;
        vector<int> dp(1<<n),cur(1<<n);
        dp[0]=1;
        for(int i=0;i<(1<<n);i++){
            if(!dp[i]) continue;
            for(int j=0;j<n;j++){
                if(cur[i]+nums[j]>part){
                    break;
                }
                if(!((i>>j)&1)){
                    if(!dp[i|(1<<j)]){
                        cur[i|(1<<j)]=(cur[i]+nums[j])%part;
                        dp[i|(1<<j)]=1;
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};
