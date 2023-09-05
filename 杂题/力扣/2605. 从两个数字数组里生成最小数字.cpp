/*
分类讨论：
1、如果二者存在公共元素，则返回那个最小的公共元素即可
2、否则选取二者中最小的元素进行组合
*/
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        for(auto a:nums1){
            for(auto b:nums2){
                if(a==b) return a;
            }
        }
        int a=*min_element(nums1.begin(),nums1.end());
        int b=*min_element(nums2.begin(),nums2.end());
        return min(a*10+b,b*10+a);
    }
};
