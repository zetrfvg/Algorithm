/*
状态定义：
dp[i][j][c]：第(i,j)格右下角的披萨分成c块的方案数
转移方程：
dp[i][j][c]=Σdp[ii][j][c-1]+Σdp[i][jj][c-1]，ii∈[i+1,n),jj∈[j+1,m)
其中(i,j)右下角披萨中苹果数须多于(ii,j)右下角披萨的苹果树和(i,jj)右下角披萨的苹果数，且(ii,j)右下角披萨和(i,jj)右下角披萨中苹果数都不为0
这里预处理出pizza的后缀和，即可以O(1)进行转移条件的判定
*/
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int mod=1e9+7;
        int n=pizza.size(),m=pizza[0].size();
        vector<vector<int>> sum(n+1,vector<int>(m+1));
        int dp[51][51][11];
        memset(dp,0,sizeof dp);
        for(int i=n-1;~i;i--){
            for(int j=m-1;~j;j--){
                sum[i][j]=sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1]+(pizza[i][j]=='A');
                dp[i][j][1]=(sum[i][j]>0);
            }
        }
        for(int c=2;c<=k;c++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    for(int ii=i+1;ii<n;ii++){
                        if(sum[i][j]>sum[ii][j]){
                            dp[i][j][c]=(dp[i][j][c]+dp[ii][j][c-1])%mod;
                        }
                    }
                    for(int jj=j+1;jj<m;jj++){
                        if(sum[i][j]>sum[i][jj]){
                            dp[i][j][c]=(dp[i][j][c]+dp[i][jj][c-1])%mod;
                        }
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};
