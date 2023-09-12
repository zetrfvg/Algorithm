/*
字符串哈希+二分
对于两个串，其最长的公共前缀长度为len，则在len之前两个串的哈希值相同，之后则不同，对len进行二分，可以logn的时间求出每个后缀的len
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
    long long sumScores(string s) {
        int n=s.size();
        StringHash sh(s);
        sh.calc();
        long long ans=0;
        for(int i=n-1;~i;i--){
            if(s[i]!=s[0]) continue;
            int l=1,r=n-i;
            while(l<r){
                int m=(l+r+1)>>1;
                if(sh.gethash(1,m)==sh.gethash(i+1,i+m)) l=m;
                else r=m-1;
            }
            ans+=l;
        }
        return ans;
    }
};
