/*
首先考虑二分，对于每个nums1[i]，我们在nums2相应的区间上二分满足条件的元素
考虑优化，双指针枚举，因为某一次需要找到nums2中对应的最远的元素，可以从上一个位置向右枚举，这时基于两个数组具有单调性
*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int ans=0;
        for(int l=0,r=0;l<n&&r<m;l++){
            while(r<m&&nums1[l]<=nums2[r]) r++;
            ans=max(ans,r-l-1);
        }
        return ans;
    }
};
