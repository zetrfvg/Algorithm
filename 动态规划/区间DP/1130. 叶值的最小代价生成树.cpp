/*
定义状态：
dp[i][j]：从第i到第j个叶子节点构成的树的非叶子节点之和
转移方程：
dp[i][j]=min(dp[i][k]+dp[k+1][j]+max1*max2)
其中，需要枚举的k为区间[i,j-1]之间的数，max1为区间[i,k]的最大值，max2为区间[k+1,j]的最大值
*/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n,1e9));
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int L=1;L<n;L++){
            for(int i=0;i<n-L;i++){
                for(int j=i;j<i+L;j++){
                    dp[i][i+L]=min(dp[i][i+L],dp[i][j]+dp[j+1][i+L]+*max_element(arr.begin()+i,arr.begin()+j+1)**max_element(arr.begin()+j+1,arr.begin()+i+L+1));                          
                }                                                   
            }
        }
        return dp[0][n-1];
    }
};
