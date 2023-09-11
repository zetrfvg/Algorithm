/*
对于一个单词考虑有多少同构的情况，首先统计出该单词各个字符出现了多少次
依次枚举各个字符，单词长度记为len
第一个字符可以放置的情况有p1=C(len,c1)种，c1为第一个字符的数量，此时能放字符的位置剩余len-p1个
同理对于第二个字符可以放置的情况有p2=C(len-p1,c2)种，之后能放字符的位置剩余len-p1-p2个
···
将所有的组合情况累乘即为该单词的同构串数量
*/
class Solution {
public:
    constexpr static int mod=1e9+7;
    using ll=long long;
    struct Comb{
        vector<int> fac;
        int n;

        Comb(int _n):n(_n),fac(_n+1){
            get_fac();
        };

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
            for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
        }

        int comb(int n,int m){
            if(m>n) return 0;
            return 1LL*fac[n]*inv(1LL*fac[n-m]*fac[m]%mod)%mod;
        }
    };
    int countAnagrams(string s) {
        Comb C(s.size()+1);
        int ans=1,sum=0;
        s+=' ';
        vector<int> cnt(26);
        for(auto c:s){
            if(c!=' ') cnt[c-'a']++,sum++;
            else{
                for(auto &k:cnt){
                    ans=1LL*ans*C.comb(sum,k)%mod;
                    sum-=k;
                    k=0;
                }
            }
        }
        return ans;
    }
};
