/*
如果存在一对相邻的元素，其和不小于m，则数组可以无限拆分下去，直到拆分成n个数组
*/
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        if(nums.size()<=2) return true;
        int mx=0;
        for(int i=1;i<nums.size();i++){
            mx=max(mx,nums[i]+nums[i-1]);
        }
        return mx>=m;
    }
};
