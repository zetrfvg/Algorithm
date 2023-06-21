/*
局部倒置必然≤全局倒置
注意到nums是一个排列，对于一某个位置i上有nums[i]>nums[i+1]
如果二者元素之间差值为1，说明这里仅有一个全局倒置和一个局部倒置
如果二者差值超过1，则说明至少存在一个元素x∈[nums[i+1],nums[i]]，使得
1、如果x在i左边，则x和nums[i+1]构成一个全局倒置
2、如果x在i+1右边，则x和nums[i]构成一个全局倒置
这样局部倒置和全局倒置一定不相等
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            if (abs(nums[i]-i)>1) {
                return 0;
            }
        }
        return 1;
    }
};
