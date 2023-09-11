/*
操作的本质即将串沿某处切割，然后把后缀拼到前面，前缀拼到后面
首先令s=s+s，来判断有多少个切割点能够使得s切割后有s=t，满足条件的切割点数量记为cnt
这里用字符串哈希,kmp算法来判断字符串是否相等即可

接下来考虑动态规划：
dp[i][0]：操作i次后得到t的方案数
dp[i][1]：操作i次后得不到t的方案数
转移方程如下：
dp[i][0]=dp[i-1][0]*(cnt-1)+dp[i-1][1]*cnt
dp[i][1]=dp[i-1][0]*(n-cnt)+dp[i-1][1](n-cnt-1)
因为k很大，递推dp状态显然超时，这里观察到上式的递推可以写成矩阵形式
[dp[i][0]]=[cnt-1， cnt  ][dp[i-1][0]]
[dp[i][1]]=[n-cnt,n-cnt-1][dp[i-1][1]]
容易想到用矩阵快速幂加速递推过程
时间复杂度：O(n+logk)
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
    int numberOfWays(string s, string t, long long k) {
        const int mod=1e9+7;
        int n=s.size();
        int cnt=0;
        StringHash a(s+s),b(t);
        a.calc(),b.calc();
        for(int i=0;i<n;i++){
            cnt+=a.gethash(i+1,i+n)==b.gethash(1,n);
        }
        vector<vector<int>> matrix{{cnt-1,cnt},{n-cnt,n-cnt-1}};
        auto mul=[&](auto &a,auto &b){
            auto res=a;
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    res[i][j]=(1LL*a[i][0]*b[0][j]+1LL*a[i][1]*b[1][j])%mod;
                }
            }
            return res;
        };
        auto pow=[&](auto &a){
            vector<vector<int>> res{{1,0},{0,1}};
            while(k){
                if(k&1) res=mul(res,a);
                a=mul(a,a);
                k>>=1;
            }
            return res;
        };
        matrix=pow(matrix);
        return matrix[0][s!=t];
    }
};
