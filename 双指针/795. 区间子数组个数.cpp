/*
双指针枚举右端点
记录[l1,r]为元素值不超过right的区间，l2为区间中离nums[r]最近的元素且在[left,right]内的元素
枚举nums[r]
如果nums[r]>right则跳过，并把l1、l2更新到r后面一个位置
如果nums[l2]在[left,right]内，则累加答案l2-l1+1
*/
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0;
        int n=nums.size();
        for(int l1=0,l2=0,r=0;r<n;r++){
            if(nums[r]>right){
                l1=l2=r+1;
                continue;
            }
            if(nums[r]>=left) l2=r;
            if(nums[l2]>=left) ans+=(l2-l1+1);
        }
        return ans;
    }
};
