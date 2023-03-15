/*
定义状态：
dp[i]为长度为i的序列能够构成的二叉搜索树的数量
转移方程：
对于长度为i的序列，我们枚举序列中所有元素作为根时能够构成的二叉搜索树的数量
如枚举元素j时，则左子树为一个长度为j-1的序列，二叉搜索树的数量为dp[j-1]；
右子树为一个i-j的序列，二叉搜索树的数量为dp[i-j]；
于是元素j作为根的二叉搜索树的数量为dp[j-1]*dp[i-j]
枚举长度为i的序列中所有元素则得到它的转移方程：
dp[i]=∑dp[j-1]*dp[i-j]
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
