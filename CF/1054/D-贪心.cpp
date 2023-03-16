/*
题目要求统计异或和不为0的区间，转换考虑异或和为0的区间
考虑第i个数，第i个元素不异或msk的前缀和为a，异或上msk的前缀和为b
再对比前面出现的a的次数与b的次数，基于贪心的思想，我们要使异或和为0的区间尽可能的少，于是：
若a>b则令该元素异或上msk，同时把前缀和为b的元素数量累加到答案ans上
若a<b则令该元素不异或msk，同样把前缀和为a的元素数量累加到答案ans上
则题目要求的的答案为(n+1)*n/2-ans

时间复杂度：O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a;i<n;i++)
#define per(i,a,n) for(int i = n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
typedef vector<int> VI;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod=998244353;
int rnd(int x) {return mrand()%x;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(int a,int b){return a*b/gcd(a,b);}

void solve(){
	int n,k;
	cin>>n>>k;
	int pre=0;
	ll ans=0;
	int a,b;
	map<int,int> g;
	g[0]=1;
	int msk=(1<<k)-1;
	rep(i,0,n){
		int x;
		cin>>x;
		a=pre^x;
		b=a^msk;
		if(g[a]>g[b]){
			pre=b;
			ans+=g[b]++;
		}else{
			pre=a;
			ans+=g[a]++;
		}
	}
	cout<<1LL*(n+1)*n/2-ans;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
