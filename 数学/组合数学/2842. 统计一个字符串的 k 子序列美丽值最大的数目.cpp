/*
遍历s，用哈希表记录出现次数为a的字符有多少种
按出现次数降序枚举，出现次数记为a，字符种数记为b
如果b<k，基于贪心，子序列种该b种字符一定都要出现，它们是当前枚举的出现次数最多的，即对答案贡献能够达到最大
如果b<=k，那么我们只能从b种字符种选取C(b,k)种，然后累乘统计答案，这里求组合数需要用到逆元
*/
class Solution {
public:
    using ll=long long;
    int countKSubsequencesWithMaxBeauty(string s, int k) {
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
        vector<int> cnt(26);
        for(auto c:s) cnt[c-'a']++;
        int ans=1;
        map<int,int> p;
        for(auto c:cnt) if(c) p[-c]++;
        for(auto &[a,b]:p){
            if(b>=k){
                for(int j=b,d=0;d<k;d++,j--){
                    ans=(1LL*ans*j)%mod;
                }
                ll v=1;
                for(int j=1;j<=k;j++) v=(1LL*v*j)%mod;
                ans=(ans*pow(v,mod-2))%mod;
                for(int j=1;j<=k;j++){
                    ans=(1LL*ans*(-a))%mod;
                }
                return ans;
            }else{
                for(int j=1;j<=b;j++){
                    ans=(1LL*ans*(-a))%mod;
                }
                k-=b;
            }
        }
        return 0;
    }
};
