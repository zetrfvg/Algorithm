/*
先直接把a扩展到b长度的两倍以上
暴力匹配找到第一个等于b的下标，计算是第几个a的重复串即可
*/
class Solution {
public:
    using ll=long long;
    struct StringHash{
        constexpr static const ll p1=197,p2=229;
        constexpr static const int M=1e6+10;
        constexpr static const int mod1=1e9+7,mod2=998244353;
        ll hash1[M],hash2[M];
        ll fac1[M],fac2[M];
        string s;
        
        StringHash(string _s):s(_s){}

        pair<ll,ll> calc(){
            int len=s.size();
            hash1[0]=hash2[0]=0;
            fac1[0]=fac2[0]=1;
            for(int i=0;i<len;i++){
                fac1[i+1]=fac1[i]*p1%mod1;
                fac2[i+1]=fac2[i]*p2%mod2;
                hash1[i+1]=(hash1[i]*p1+s[i])%mod1;
                hash2[i+1]=(hash2[i]*p2+s[i])%mod2;
            }
            return make_pair(hash1[len],hash2[len]);
        }

        pair<ll,ll> gethash(int l,int r){//获取子串的hash
            ll h1=(hash1[r]-(hash1[l-1]*fac1[r-l+1]%mod1)+mod1)%mod1;
            ll h2=(hash2[r]-(hash2[l-1]*fac2[r-l+1]%mod2)+mod2)%mod2;
            return make_pair(h1,h2);
        }
    };
    int repeatedStringMatch(string a, string b) {
        string aa=a+a;
        int n=b.size();
        while(aa.size()<b.size()*2) aa+=a;
        StringHash sa(aa),sb(b);
        sa.calc(),sb.calc();
        for(int i=0;i+n+1<=aa.size();i++){
            if(sa.gethash(i+1,i+n)==sb.gethash(1,n)) return (i+n+a.size()-1)/a.size();
        }
        return -1;
    }
};
