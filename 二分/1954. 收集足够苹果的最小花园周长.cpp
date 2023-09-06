/*
对于右上角为(n,n)的正方形，其内部苹果数量为2n(n+1)(2n+1)
*/
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long l=1,r=1e6;
        while(l<r){
            int m=(l+r)>>1;
            if(1LL*2*m*(m+1)*(2*m+1)>=neededApples) r=m;
            else l=m+1;
        }
        return l<<3;
    }
};
