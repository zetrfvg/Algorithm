/*
状态定义：
dp[i][j]：前i个会议中，参加至多j个会议能够获得的最大价值
转移方程：
dp[i][j]=max(dp[i-1][j],dp[l][j-1]+events[i-1][2]),l是满足event[l][1]<event[i][0]的最大的l

优化：
考虑要找到最大的l，因此可以首先预处理event按第二关键字排序
通过排序，每次就可以通过二分找到这个l
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int dp[n+1][k+1];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            int l=0,r=i-1;
            while(l<r){
                int m=(l+r)>>1;
                if(events[m][1]<events[i-1][0]) l=m+1;//因为l对应event数组中的l，这里对应状态dp[l+1]，于是l需要取m+1
                else r=m;
            }
            for(int j=1;j<=k;j++){
                dp[i][j]=max(dp[i-1][j],dp[l][j-1]+events[i-1][2]);
            }
        }
        return dp[n][k];
    }
};
