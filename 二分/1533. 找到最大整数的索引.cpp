/*
二分，如果区间[l,r]长度为偶数，则比较[l,m]和[m+1,r]；否则比较[l,m]和[m,r]
*/
class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int l=0,r=reader.length()-1;
        while(l<r){
            int m=(l+r)>>1;
            if((r-l+1)&1){
                int res=reader.compareSub(l,m,m,r);
                if(!res) return m;
                else if(res==1) r=m;
                else l=m;
            }else{
                int res=reader.compareSub(l,m,m+1,r);
                if(res==1) r=m;
                else l=m+1;
            }
        }
        return l;
    }
};
