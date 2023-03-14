/*
基于贪心的一种构造
对于位置ans[i][j]，他能取到的最大值为rowSum[i]和colSum[j]中的最小值
可以贪心直接令该位置取最大值即可，同时要更新rowSum[i]-=ans[i][j]，colSum[j]-=ans[i][j]
利用数学归纳法可以证明满足要求
*/
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(),m=colSum.size();
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=min(rowSum[i],colSum[j]);
                rowSum[i]-=ans[i][j];
                colSum[j]-=ans[i][j];
            }
        }
        return ans;
    }
};
