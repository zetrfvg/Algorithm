/*
状态定义：
dp[i]：完成集合为i的任务所需的最少时间段
*/
class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        vector<int> st(1<<n);
        for(int i=1;i<(1<<n);i++){//首先预处理出所有时间加起来不超过sessionTime的组合
            int time=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) time+=tasks[j];
            }
            if(time<=sessionTime) st[i]=1;
        }
        vector<int> dp(1<<n,1e9);
        dp[0]=0;
        for(int i=1;i<(1<<n);i++){//枚举所有状态
            for(int j=i;j;j=(j-1)&i){//枚举子集
                if(st[j]){//完成该子集任务的时间不超过sessionTime，则进行转移
                    dp[i]=min(dp[i],dp[i^j]+1);
                }
            }
        }
        return dp.back();
    }
};
