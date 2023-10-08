/*
特判0，如果存在0，则长度最短为1
其余情况，顺序遍历，如果乘积不大于k，则最终长度减少1
*/
class Solution {
public:
    int minArrayLength(vector<int>& nums, int k) {
        if(count(nums.begin(),nums.end(),0)) return 1;
        int n=nums.size(),ans=n,mul=nums[0];
        for(int i=1;i<n;i++){
            if(1LL*mul*nums[i]>k) mul=nums[i];
            else ans--,mul*=nums[i];
        }
        return ans;
    }
};
