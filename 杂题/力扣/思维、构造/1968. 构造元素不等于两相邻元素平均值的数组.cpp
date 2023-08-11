/*
排序之后，排列放置按 小-大-小-大-小……放置
可以证明，两个大于nums[i]的元素的平均值不可能等于nums[i]，同样两个小于nums[i]的元素的平均值不可能等于nums[i]
基于此，贪心放置即可
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        for(int i=0,l=0,r=n-1;i<n;i++){
            if(i&1) ans[i]=nums[l++];
            else ans[i]=nums[r--];
        }
        return ans;
    }
};
