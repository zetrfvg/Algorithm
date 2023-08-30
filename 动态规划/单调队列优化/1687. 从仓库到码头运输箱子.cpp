/*
预处理前缀和：
1、求出一次运送前i个物品的形成cost[i]=cost[i-1]+(boxes[i-1][0]!=boxes[i][0])
2、求出前i个物品的重量和w[i]=w[i-1]+boxes[i][1]

状态定义：
dp[i]：运送前i个物品的最少的行程数
转移方程：
dp[i]=min(dp[j]+cost[i]-cost[j+1]+2)，j<i
这样的转移是O(n²)的

观察式子，发现dp[j]-cost[j+1]是与i无关的，说明dp[i]只由最小的dp[j]-cost[j+1]转移而来，因此需要一个数据结构来维护最小值
维护区间内的最值，这里是经典的单调队列使用场景，即可优化到O(n)
*/
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n=boxes.size();
        vector<int> cost(n+1);
        vector<long long> w(n+1);
        for(int i=0;i<n;i++){//预处理前缀数组
            w[i+1]=w[i]+boxes[i][1];
            if(i) cost[i+1]=cost[i]+(boxes[i-1][0]!=boxes[i][0]);
        }
        deque<int> q{0};
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            while(!q.empty()&&(i-q.front()>maxBoxes||w[i]-w[q.front()]>maxWeight)){//物品数量过多或重量超重
                q.pop_front();
            }
            dp[i]=dp[q.front()]-cost[q.front()+1]+cost[i]+2;//用队头最小的状态进行转移
            if(i!=n){//状态dp[i]-cost[i+1]入队
                while(!q.empty()&&dp[i]-cost[i+1]<=dp[q.back()]-cost[q.back()+1]){
                    q.pop_back();
                }
                q.push_back(i);
            }
        }
        return dp[n];
    }
};
