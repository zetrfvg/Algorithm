/*
DP+双指针
状态定义：
dp[i]：排序后数组第i个元素为根时构成的树的方案数
因为不存在1，枚举每个数arr[i]作为因子，其左右儿子的值一定都小于arr[i]
首先对数组排序，从小到大考虑每个arr[i]作为根结点时的方案数
枚举到arr[i]，枚举它的因子对时用双指针来枚举
枚举左端点，如果左右指针指向的元素之积大于arr[i]则移动右指针
如果左右指针指向的元素之积等于arr[i]，需要分情况讨论
如果l==r，说明两个指针指向同一个元素，此时arr[i]为根，左右儿子都为arr[l]时的方案数为dp[l]*dp[l]
如果l!=r，说明两个指针指向了不同元素，此时arr[i]为根，左右儿子分别可以为arr[l],arr[r]或者为arr[r],arr[l]，所有方案数为dp[l]*dp[r]*2
此外，还有整棵树仅有一个根结点的情况
转移方程：
dp[i]=1+Σdp[l]*dp[r]*C，其中l==r时C=1，否则C=2
*/
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod=1e9+7;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int l=0,r=i-1;l<=r;l++){
                while(l<=r&&1LL*arr[l]*arr[r]>arr[i]) r--;
                if(l<=r&&1LL*arr[l]*arr[r]==arr[i]){
                    dp[i]=(1LL*dp[i]+1LL*dp[l]*dp[r]*(1+(l!=r)))%mod;
                }
            }
            ans=(1LL*ans+dp[i])%mod;
        }
        return ans;
    }
};
