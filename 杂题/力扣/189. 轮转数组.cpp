/*
三次翻转
先翻转前n-k个数
再翻转后k个数
最后翻转整个数组
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.rbegin(),nums.rbegin()+k);
        reverse(nums.begin(),nums.end());
    }
};
