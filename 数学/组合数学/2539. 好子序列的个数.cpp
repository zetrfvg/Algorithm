/*
预处理各个字符出现的次数
然后枚举字符出现的次数i，如果字符出现了c(c>i)次，则该字符当前的贡献为C(c,i)+1//选这个字符出现在子序列中有C(c,i)种选法，不选这个字符则有1种选法，二者累加为当前贡献
把所有出现次数超过i的字符其贡献累乘起来再减去1(减去空集，空集不合法)，即为各个字符出现次数为i的子序列数量
同样这里组合数的阶乘及其逆元都需要预处理
*/
Class Solution {
public:

    Solution(){
        get_fac();
    }

    static const int mod=1e9+7,N=1e4+10;
    using ll=long long;
    int fac[N];

    ll pow(ll a,ll b){
        ll res=1;
        while(b){
            if(b&1) res=res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res;
    }

    ll inv(ll x){
        return pow(x,mod-2);
    }

    void get_fac(){
        fac[0]=1;
        for(int i=1;i<N-1;i++) fac[i]=1LL*fac[i-1]*i%mod;
    }

    int comb(int n,int m){
        if(m>n) return 0;
        return 1LL*fac[n]*inv(1LL*fac[n-m]*fac[m]%mod)%mod;
    }

    int countGoodSubsequences(string s) {
        vector<int> cnt(26);
        int ans=0,mx=0;
        for(auto c:s) mx=max(mx,++cnt[c-'a']);
        for(int i=1;i<=mx;i++){
            int cur=1;
            for(auto c:cnt){
                if(c<i) continue;
                cur=1LL*cur*(comb(c,i)+1LL)%mod;
            }
            ans=(1LL*ans+cur-1+mod)%mod;
        }
        return ans;
    }
};
