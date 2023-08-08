/*
快速幂应用题
*/
class Solution {
public:
    using ll=long long;
    int countGoodNumbers(long long n) {
        const int mod=1e9+7;
        auto pow=[&](ll a,ll b){
            ll res=1;
            while(b){
                if(b&1) res=res*a%mod;
                a=a*a%mod;
                b>>=1;
            }
            return res;
        };
        ll ans=0;
        ans=pow(4,n/2)*pow(5,(n+1LL)/2)%mod;
        return ans;
    }
};
