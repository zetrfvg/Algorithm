/*
二分套二分
先二分答案ans，在二分查找统计有多少个数大于等于ans
二分查找时枚举nums1中的元素要分类讨论，按正负来进行二分
*/
class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n=nums2.size();
        long long l=-1e14,r=1e14;
        auto check=[&](long long m){
            long long res=0;
            for(long long x:nums1){
                if(x>0){
                    if(x*nums2[0]>m) continue;
                    int l=0,r=n-1;
                    while(l<r){
                        int mid=(l+r+1)>>1;
                        if(x*nums2[mid]<=m) l=mid;
                        else r=mid-1;
                    }
                    res+=l+1;
                }else if(x<0){
                    if(x*nums2.back()>m) continue;
                    int l=0,r=n-1;
                    while(l<r){
                        int mid=(l+r)>>1;
                        if(x*nums2[mid]>m) l=mid+1;
                        else r=mid;
                    }
                    res+=n-l;
                }else if(m>=0){
                    res+=n;
                }
            }
            return res;
        };
        while(l<r){
            long long m=(l+r)>>1;
            if(check(m)<k) l=m+1;
            else r=m;
        }
        return l;
    }
};
