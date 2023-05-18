/*
每次选择最小的数操作＋1
时间复杂度：O((n+k)logn)
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>> q(nums.begin(),nums.end());
        int ans=1;
        while(k--){
            int x=q.top();
            q.pop();
            q.push(x+1);
        }
        while(!q.empty()){
            int x=q.top();
            q.pop();
            ans=1LL*ans*x%mod;
        }
        return ans;
    }
};
