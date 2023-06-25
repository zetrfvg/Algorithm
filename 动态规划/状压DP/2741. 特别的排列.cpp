/*
状态定义：
dp[i][j]：放置了子集为i的元素，且放置的最后一个元素为j时的方案数
*/
class Solution {
public:
    using ll=long long;
    static const int mod=1e9+7;
    int specialPerm(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>> dp(1<<n,vector<ll>(n));
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int ii=i^(1<<j);
                    if(!ii){
                        dp[i][j]=1;
                        break;
                    }
                    for(int jj=0;jj<n;jj++){
                        if(ii&(1<<jj)){
                            if(nums[jj]%nums[j]==0||nums[j]%nums[jj]==0){
                                dp[i][j]=(dp[i][j]+dp[ii][jj])%mod;
                            }
                        }
                    }
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            ans=(ans+dp[(1<<n)-1][i])%mod;
        }
        return ans;
    }
};
