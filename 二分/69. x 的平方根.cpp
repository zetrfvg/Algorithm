/*
二分做法
*/
class Solution {
public:
    int mySqrt(int x) {
        int l=0,r=5e4;
        while(l<r){
            int m=(l+r+1)>>1;
            if(1LL*m*m<=x) l=m;
            else r=m-1;
        }
        return l;
    }
};
