/*
二分+双指针
check函数，枚举第i只鸡可以吃哪些米时，可能存在该鸡左右两边都存在可以吃的米
判断其是否能吃到它左边位置l到右边位置r上的所有米的话，鸡必定掉头一次，因此只需满足min(l*2+r,l+r*2)<=二分的时间
*/
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        int n=hens.size(),m=grains.size();
        sort(hens.begin(),hens.end());
        sort(grains.begin(),grains.end());
        auto check=[&](long long k){
            int j=0;
            for(int i=0;i<n;i++){
                int l=0,r=0;
                while(j<m){
                    if(grains[j]<hens[i]) l=max(l,hens[i]-grains[j]);
                    else if(grains[j]>hens[i]) r=max(r,grains[j]-hens[i]);
                    if(min(l*2+r,l+r*2)<=k) j++;
                    else break;
                }
            }
            return j==m;
        };
        long long l=0,r=1e11;
        while(l<r){
            long long mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
