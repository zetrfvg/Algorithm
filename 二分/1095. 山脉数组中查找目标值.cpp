/*
首先二分找到峰顶的位置
然后在左边二分找target
如果找不到再再右边二分找target
*/
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int l=0,r=n-1;
        while(l<r){
            int m=(l+r)>>1;
            if(mountainArr.get(m)<mountainArr.get(m+1)) l=m+1;
            else r=m;
        }
        int top=l;
        l=0,r=top;
        while(l<r){
            int m=(l+r)>>1;
            if(mountainArr.get(m)<target) l=m+1;
            else r=m;
        }
        if(mountainArr.get(l)==target) return l;
        l=top,r=n-1;
        while(l<r){
            int m=(l+r)>>1;
            if(mountainArr.get(m)>target) l=m+1;
            else r=m;
        }
        if(mountainArr.get(l)==target) return l;
        else return -1;
    }
};
