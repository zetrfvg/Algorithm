/*
找到两个最值的位置l,r
三种情况取最小值：
1、左边移除一段+右边移除一段
2、左边移除一段
3、右边移除一段
*/
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int l=min_element(nums.begin(),nums.end())-nums.begin();
        int r=max_element(nums.begin(),nums.end())-nums.begin();
        if(l>r) swap(l,r);
        return min({l+1+n-r,r+1,n-l});
    }
};
