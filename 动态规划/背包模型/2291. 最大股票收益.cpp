/*
状态定义：
dp[i][j]：考虑前i个物品，预算为j的最大收益
很裸的0/1背包，实现使用了滚动数组
*/
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        vector<int> dp(budget+1);
        int n=present.size();
        for(int i=0;i<n;i++){
            for(int j=budget;j>=present[i];j--){
                dp[j]=max(dp[j],dp[j-present[i]]+future[i]-present[i]);
            }
        }
        return dp[budget];
    }
};
