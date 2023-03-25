/*
状态定义：
dp[i][j]：使用i+1个鸡蛋来验证j层楼的最少操作数
转移方程：
dp[i][j]=min(max(dp[d-1][j]+1,dp[i-d][j]+1))，d取值为[1,i]之间的所有整数

状态定义是二维，转移需要取最值，这个式子的复杂度为(kn^2)
接下来考虑优化
观察到性质：
如果鸡蛋的数量不变，随着层数的增加，最少操作的次数一定是单调递增的
基于这个单调性，观察式子中的dp[d-1][j]与dp[i-d][j]
前者是关于d的单调递增函数，后者是关于d的单调递减函数
我们期望取值d能够让它们的最大值最小，那么显然是在两个函数的交点处取到最小值
由此考虑二分，
令y1=dp[d-1][j],y2=dp[i-d][j]
二分这个交点x0，x0不一定是整数，因此我们最终需要在离他最近的两个整数中比较取得这个期望最小值
如果y1>y2，则右端点左移
如果y1<y2，则左端点右移
否则，左右端点等于中间端点
复杂度：O(nklogn)
*/
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k,1e9));
        for(int i=0;i<k;i++) dp[0][i]=0;
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=1;i<=n;i++){
            for(int j=1;j<k;j++){
                int l=1,r=i;
                while(r-l>1){
                    int m=(l+r)>>1;
                    int y1=dp[m-1][j-1];
                    int y2=dp[i-m][j];
                    if(y1>y2) r=m;
                    else if(y1<y2) l=m;
                    else l=r=m;
                }
                dp[i][j]=min(max(dp[l-1][j-1],dp[i-l][j]),max(dp[r-1][j-1],dp[i-r][j]))+1;
            }
        }
        return dp[n][k-1];
    }
};
