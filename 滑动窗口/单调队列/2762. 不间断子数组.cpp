/*
用两个单调队列来维护区间最大值和最小值，当二者差超过2时移动左指针
*/
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        deque<int> mx,mn;
        for(int l=0,r=0;r<n;r++){
            while(!mx.empty()&&nums[r]>=nums[mx.back()]) mx.pop_back();
            mx.push_back(r);
            while(!mn.empty()&&nums[r]<=nums[mn.back()]) mn.pop_back();
            mn.push_back(r);
            while(nums[mx.front()]-nums[mn.front()]>2){
                if(mx.front()==l) mx.pop_front();
                if(mn.front()==l) mn.pop_front();
                l++;
            }
            ans+=1LL*(r-l+1);
        }
        return ans;
    }
};
