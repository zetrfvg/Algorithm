/*
求前缀和数组
枚举右端点，用一个单调队列来维护最长的区间满足区间和小于k
如果队尾元素大于当前元素，弹出队尾
如果队列中维护的区间中所有元素和大于等于k，此时更新答案，然后弹出队头元素，直至整个区间元素小于k
*/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> s(n+1);
        for(int i=0;i<n;i++) s[i+1]=1LL*s[i]+nums[i];
        deque<int> q;
        int ans=1e9;
        for(int i=0;i<=n;i++){
            while(!q.empty()&&s[i]<s[q.back()]) q.pop_back();
            q.push_back(i);
            while(!q.empty()&&s[i]-s[q.front()]>=k){
                ans=min(ans,i-q.front());
                q.pop_front();
            }
        }
        return ans==1e9?-1:ans;
    }
};
