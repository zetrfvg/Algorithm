/*
机器人相撞后各自回头等于没有相撞，继续向前移动
由此先预处理出各个机器人最终的位置
计数的过程则是一个经典的前后缀分解
*/
class Solution {
public:
    int sumDistance(vector<int>& a, string s, int d) {
        const int mod=1e9+7;
        int n=a.size();
        vector<long long> sum(n);
        for(int i=0;i<n;i++){
            if(s[i]=='L'){
                sum[i]=1LL*a[i]-d;
            }else{
                sum[i]=1LL*a[i]+d;
            }
        }
        sort(sum.begin(),sum.end());
        long long ans=0;
        long long suf=accumulate(sum.begin(),sum.end(),0LL);
        long long pre=0;
        for(int i=0;i<n;i++){
            suf-=sum[i];
            long long r=suf-(1LL*n-i-1)*sum[i];
            long long l=(1LL*i)*sum[i]-pre;
            ans=(ans+l+r)%mod;
            pre+=sum[i];
        }
        return ans&1?(ans+mod)/2:ans/2;
    }
};
