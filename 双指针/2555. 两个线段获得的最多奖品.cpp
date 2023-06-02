/*
双指针枚举右端点，如果区间长超过了k则移动左端点
用dp[i]来记录前i个奖品中，区间长为k最多能覆盖的奖品数
转移方程：
dp[r+1]==max(r-l+1,dp[r])
*/
class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n=prizePositions.size();
        int ans=0;
        vector<int> dp(n+1);
        for(int l=0,r=0;r<n;r++){
            while(prizePositions[r]-prizePositions[l]>k) l++;
            ans=max(ans,r-l+1+dp[l]);
            dp[r+1]=max(r-l+1,dp[r]);
        }
        return ans;
    }
};
