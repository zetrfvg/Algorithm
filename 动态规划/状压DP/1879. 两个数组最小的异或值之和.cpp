/*
状态定义：
用一个二进制数来表示nums2中哪些数被选了
dp[i]：i表示从nums2中选了哪些数，i中1的个数cnt表示选到了nums1中第cnt个数
转移方程：
dp[i]=min(dp[i],dp[i^(1<<j)]+(nums1[__builtin_popcount(i)-1]^nums2[j]))
*/
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int dp[1<<n];
        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for(int i=1;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    dp[i]=min(dp[i],dp[i^(1<<j)]+(nums1[__builtin_popcount(i)-1]^nums2[j]));
                }
            }
        } 
        return dp[(1<<n)-1];
    }
};
