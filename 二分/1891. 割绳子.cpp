/*
二分答案
check线性扫描判断即可
*/
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int n=ribbons.size();
        if(accumulate(ribbons.begin(),ribbons.end(),0LL)<k) return 0;
        int l=1,r=1e9;
        auto check=[&](int m){
            int res=0;
            for(int i=0;i<n;i++) res+=ribbons[i]/m;
            return res>=k;
        };
        while(l<r){
            int m=(l+r+1)>>1;
            if(check(m)) l=m;
            else r=m-1;
        }
        return l;
    }
};
