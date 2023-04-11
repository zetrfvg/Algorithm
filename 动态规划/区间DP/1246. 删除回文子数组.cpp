/*
状态定义：
dp[l][r]：删除区间[l,r]的子数组所需的最少操作数
转移方程：
考虑区间长度len小于等于2的情形：
len==1时：则显然所有dp[l][r]=1
len==2时：则分为arr[l]==arr[r]和arr[l]!=arr[r]两种情况，统一处理为dp[l][r]=1+(arr[l]!=arr[r]);
len>=3时：同样分为arr[l]==arr[r]和arr[l]!=arr[r]两种情况：
          arr[l]!=arr[r]时，把[l,r]分成两个区间来删除，直接转移即可，dp[l][r]=min(dp[l][k],dp[k+1][r])，k∈[l,r-1]
          arr[l]==arr[r]时，考虑删除[l+r,r-1]区间最后一步一定是个回文序列，把arr[l]和arr[r]加在这个序列的两端仍然是一个回文序列，
          无需增加删除次数即可一同删除掉两端，于是有dp[l][r]=dp[l+1][r-1]。如果不把arr[l]和arr[r]放在一个序列中删除，则和前一种情况一样进行转移
*/
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n=arr.size();
        int dp[n][n];
        memset(dp,0x3f,sizeof dp);
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i<n-1) dp[i][i+1]=1+(arr[i]!=arr[i+1]);
        }
        for(int len=3;len<=n;len++){
            for(int l=0,r=len-1;r<n;l++,r++){
                if(arr[l]==arr[r]){
                    dp[l][r]=dp[l+1][r-1];
                }
                for(int k=l;k<r;k++){
                    dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};
