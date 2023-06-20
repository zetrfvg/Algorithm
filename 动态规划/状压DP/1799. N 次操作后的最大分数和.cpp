/*
状态定义：
dp[i]：选取状态为i的子集，执行若干次操作后，获得的最大分数
转移方程：
枚举子集， 子集中元素的个数必须为偶数，然后枚举任意两个元素作为最后一次操作时能够获得的最大值
*/
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(1<<n);
        vector<vector<int>> gcd(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gcd[i][j]=__gcd(nums[i],nums[j]);
            }
        }
        for(int i=1;i<(1<<n);i++){
            if(__builtin_popcount(i)&1) continue;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    int ii=i^(1<<j);
                    for(int jj=0;jj<n;jj++){
                        if(ii&(1<<jj)){
                            int cnt=__builtin_popcount(i)/2;
                            dp[i]=max(dp[i],dp[ii^(1<<jj)]+cnt*gcd[j][jj]);
                        }
                    }
                }
            }
        }
        return dp.back();
    }
};
