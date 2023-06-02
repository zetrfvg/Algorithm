/*
用cost来记录区间runningCosts的和，单调队列来维护区间中最大的chargeTimes
双指针枚举右端点r，如果chargeTimes[r]，则弹出队尾元素
计算区间内的代价和，如果超过了budget则移动左指针，如果左指针和队头元素相同，那么还需要弹出队头元素
用区间长更新答案
*/
class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long cost=0;
        int n=chargeTimes.size();
        int ans=0;
        deque<int> q;
        for(int l=0,r=0;r<n;r++){
            cost+=runningCosts[r];
            while(!q.empty()&&chargeTimes[q.back()]<chargeTimes[r]) q.pop_back();
            q.push_back(r);
            while(!q.empty()&&1LL*chargeTimes[q.front()]+cost*(1LL*r-l+1)>budget){
                if(q.front()==l) q.pop_front();
                cost-=runningCosts[l++];
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
