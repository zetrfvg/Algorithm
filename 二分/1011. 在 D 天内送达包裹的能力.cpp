/*
二分答案，check模拟即可
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(weights.begin(),weights.end()),r=1e9;
        auto check=[&](int lim){
            int s=0,res=1;
            for(int i=0;i<n;i++){
                if(s+weights[i]>lim){
                    s=0,res++;
                }
                s+=weights[i];
            }
            return res<=days;
        };
        while(l<r){
            int m=(l+r)>>1;
            if(check(m)) r=m;
            else l=m+1;
        }
        return l;
    }
};
