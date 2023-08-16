/*
预处理，筛出所有质数，并求出各个元素的质数分数
对于每个元素nums[i]，分别找到它左边最近的质数分数大于等于它的元素nums[l]和它右边最近的质数分数大于它的元素nums[r]，这里是经典的单调栈能够求解的问题
基于乘法原理，能够贡献出nums[i]子数组的数量为(i-l)*(r-i)
所有从大到小排序，选取k个子数组作乘法即可，这里还需要用到快速幂
*/
int flag=1;
static const int N=1e5+100;
int vis[N];
int prim[N];
int cnt;
int score[N];
int st[N],top=0;

void Euler(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]) prim[++cnt]=i;
        for(int j=1;1LL*i*prim[j]<=n;j++){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0) break;
        }
    }
}
class Solution {
public:
    using ll=long long;
    int maximumScore(vector<int>& nums, int k) {
        top=0;
        if(flag){
            memset(vis,0,sizeof vis);
            memset(score,-1,sizeof score);
            Euler(100050);
            flag=0;
        }
        int n=nums.size();
        vector<array<int,3>> a(n);
        for(int i=0;i<n;i++){
            int s=0;
            a[i][0]=nums[i],a[i][1]=s,a[i][2]=i;
            if(score[nums[i]]!=-1) s=score[nums[i]];
            else{
                int y=nums[i];
                for(int j=1;1LL*prim[j]<=nums[i];j++){
                    if(nums[i]%prim[j]==0) s++;
                    while(nums[i]%prim[j]==0) nums[i]/=prim[j];
                }
                score[y]=s;
            }
            a[i][1]=s;
        }
        vector<int> l(n,-1),r(n,n);
        for(int i=n-1;~i;i--){
            while(top&&a[st[top]][1]<=a[i][1]){
                l[st[top]]=i;
                top--;
            }
            st[++top]=i;
        }
        top=0;
        for(int i=0;i<n;i++){
            while(top&&a[st[top]][1]<a[i][1]){
                r[st[top]]=i;
                top--;
            }
            st[++top]=i;
        }
        const int mod=1e9+7;
        ll ans=1;
        auto pow=[&](ll a,ll b){
            ll res=1;
            while(b){
                if(b&1) res=res*a%mod;
                a=a*a%mod;
                b>>=1;
            }
            return res;
        };
        sort(a.begin(),a.end(),greater<>());
        for(int i=0;i<n;i++){
            ll x=a[i][0];
            int j=a[i][2];
            int ll=j-l[j],rr=r[j]-j;
            if(1LL*rr*ll>=k){
                ans=(ans*1LL*pow(x,k))%mod;
                break;
            }
            ans=(ans*1LL*pow(x,1LL*rr*ll))%mod;
            k-=ll*rr;
        }
        return ans;
    }
};
