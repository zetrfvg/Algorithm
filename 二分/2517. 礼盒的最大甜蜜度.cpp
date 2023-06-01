/*
先对数组进行排序，再二分
基于贪心，我们从数组中选取了一个物品，那么下一个物品和它的差值必须大于等于二分的这个值且要离这个物品最近
*/
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size();
        auto check=[&](int m){
            int res=0,last=-1e9;
            for(int i=0;i<n;i++){
                if(price[i]-last>=m){
                    res++,last=price[i];
                }
            }
            return res>=k;
        };
        int l=0,r=1e9;
        while(l<r){
            int m=(l+r+1)>>1;
            if(check(m)) l=m;
            else r=m-1;
        }
        return l;
    }
};
