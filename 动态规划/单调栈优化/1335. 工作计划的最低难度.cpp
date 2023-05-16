/*
状态定义：
dp[i][j]：前i天完成前j个任务的最低难度
转移方程：
dp[i][j]=min(dp[i-1][k-1]+max(jobDifficulty[i~j]))，其中k∈[i,j]

优化:
[2,1,3,6,8,1,3,7]
当枚举到最后一个任务job[7]=7时，我们找到左边离他最近且大于它的元素job[4]=8，
如果不把job[4]和job[8]放在同一天完成
那么dp[i][7]=min(dp[i-1][5],dp[i-1][6])+7
如果把job[4]和job[8]放在同一天完成
那么dp[i][7]=dp[i-1][4]
二者取最小值即可

由于是左侧最近的更大元素，由此考虑使用单调栈
*/
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>> dp(d,vector<int>(n,1e9));
        int mn=0;
        for(int i=0;i<n;i++){
            mn=max(mn,jobDifficulty[i]);
            dp[0][i]=mn;
        }
        for(int i=1;i<d;i++){
            stack<pair<int,int>> st;
            for(int j=i;j<n;j++){
                int mn=dp[i-1][j-1];
                while(!st.empty()&&jobDifficulty[st.top().first]<=jobDifficulty[j]){
                    mn=min(st.top().second,mn);
                    st.pop();
                }
                dp[i][j]=mn+jobDifficulty[j];
                if(!st.empty()){
                    dp[i][j]=min(dp[i][j],dp[i][st.top().first]);
                }
                st.push({j,mn});
            }
        }
        return dp[d-1][n-1];
    }
};
