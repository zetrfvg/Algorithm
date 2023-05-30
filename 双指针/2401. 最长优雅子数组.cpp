/*
双指针枚举右端点，找到与运算结果为0的最长子数组，模拟即可
实现用到了位运算的trick
*/
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0,st=0;
        for(int l=0,r=0;r<n;r++){
            while((st&nums[r])){
                st^=nums[l++];
            }
            st|=nums[r];
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
