/*
每次从堆中选取最大的元素操作即可
*/
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> q;
        for(auto c:nums) q.push(c);
        while(k--){
            int x=q.top();
            q.pop();
            ans+=x;
            q.push((x+2)/3);
        }
        return ans;
    }
};
