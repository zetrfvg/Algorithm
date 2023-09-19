/*
枚举机器，二分答案
*/
class Solution {
public:
    using ll=long long;
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        ll ans=0;
        auto check=[&](int i,ll m){
            long long c=0;
            for(int j=0;j<n;j++){
                ll p=m*composition[i][j];
                if(stock[j]>=p) continue;
                c+=(p-stock[j])*cost[j];
                if(c>budget) return false;
            }
            return c<=budget;
        };
        for(int i=0;i<k;i++){
            int cur=0;
            ll l=0,r=1e14;
            while(l<r){
                ll m=(l+r+1)>>1;
                if(check(i,m)) l=m;
                else r=m-1;
            }
            ans=max(ans,l);
        }
        return ans;
    }
};
