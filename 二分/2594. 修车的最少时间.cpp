/*
二分答案
答案显然具有单调性
低于某个时间点一定修不完所有的cars
高于某个时间点一定能够修完
二分这个时间点即可
*/
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0,r=1e16;
        sort(ranks.begin(),ranks.end());
        int n=ranks.size();
        auto check=[&](long long m){
            long long c=0;
            for(int i=0;i<n;i++){
                c+=1LL*sqrt(m/ranks[i]);
            }
            return c>=cars;
        };
        while(l<r){
            long long m=(l+r)>>1;
            if(check(m)) r=m;
            else l=m+1;
        }
        return l;
    }
};
