/*
排序+双指针
因为操作只能加1，所以考虑先排序，依次从小到大枚举各个元素作为频数最高元素的开销
双指针枚举右端点r，前一元素nums[r-1]作为频数最高元素的开销为cost
那么以nums[r]作为频数最高元素的开销变为cost+(r-l)*(nums[r]-nums[r-1])
如果开销超过了k则移动左指针
最长的合法区间即为答案
*/
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long cost=0;
        int ans=1;
        for(int l=0,r=1;r<n;r++){
            cost+=1LL*(r-l)*(nums[r]-nums[r-1]);
            while(cost>k){
                cost-=nums[r]-nums[l++];
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
