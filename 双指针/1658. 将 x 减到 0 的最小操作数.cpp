/*
记nums元素和为sum
从数组两边选走最少的元素，使之和为x
等价于nums中找一个最长的区间，其元素和为sum-x
经典双指针枚举即可
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=-1,cur=0;
        int target=accumulate(nums.begin(),nums.end(),0)-x;
        if(target<0) return -1;
        for(int l=0,r=0;r<n;r++){
            cur+=nums[r];
            while(cur>target) cur-=nums[l++];
            if(cur==target) ans=max(ans,r-l+1);
        }
        return ans==-1?-1:n-ans;
    }
};
