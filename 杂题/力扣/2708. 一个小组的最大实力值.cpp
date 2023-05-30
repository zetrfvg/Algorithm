/*
正数全选，负数从小到大每两个一选，细节较多
*/
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        bool ok=0;
        long long ans=1;
        priority_queue<int> q;
        for(auto c:nums){
            if(c>0) ans*=1LL*c,ok=1;
            else if(c<0) q.push(-c);
        }
        while(q.size()>1){
            ok=1;
            ans*=1LL*q.top();
            q.pop();
            ans*=1LL*q.top();
            q.pop();
        }
        return !ok?0LL:ans;
    }
};
