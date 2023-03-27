/*
首先对工作按结束时间排序
状态定义：
dp[i]：前i个工作中，能够挣取的最大价值
转移方程：
dp[i]=max(dp[i-1],dp[l]+e[i-1][2]),l是满足e[l][1]<=e[i][0]的最大一个位置
因为通过排序，e[i][1]是单调的，因此可以通过二分来找到l
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> e(n);
        int dp[n+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            e[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(e.begin(),e.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        for(int i=1;i<=n;i++){
            int l=0,r=i-1;
            while(l<r){
                int m=(l+r)>>1;
                if(e[m][1]<=e[i-1][0]) l=m+1;
                else r=m;
            }
            dp[i]=max(dp[i-1],dp[l]+e[i-1][2]);
        }
        return dp[n];
    }
};
