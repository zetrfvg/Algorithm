/*
假设放置了i-1个快递，其方案数为f[i-1]
对于这个长为2*(i-1)的排列，我们考虑如何放置第i个快递
将其收件服务如果放在排列最左边，则配送服务有2*(i-1)+1个放法；如果收件服务放在第一个服务之后，则配送服务有2*(i-1)种放法······
递推下去，第i个物品总共有(2*i)*(2*i-1)/2种放法
那么放置所有i个物品的方案，通过递推可以知道为(2*i)*(2*i-1)/2*f[i-1]
于是得出通项公式f[n]=(2n)!/(2^n)
对于/(2^n)，需要处理逆元
*/
class Solution {
public:
    int countOrders(int n) {
        const int mod=1e9+7;
        long long fac=1,pow=1;
        for(long long i=0,j=1;i<n;i++,j+=2){
            fac=fac*1LL*j*(j+1)%mod;
            pow=pow*2%mod;
        }
        long long a=1,b=mod-2;
        while(b){
            if(b&1) a=a*pow%mod;
            pow=pow*pow%mod;
            b>>=1;
        }
        return fac*a%mod;
    }
};
