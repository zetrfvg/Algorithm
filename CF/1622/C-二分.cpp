/*
操作的次数低于某一次数一定不可能小于等于k，大于某一次数一定可以大于k
因此答案具有单调性，二分这个临界值
二分操作次数m，我们每次操作1的次数记为c1，操作2的次数记为c2
基于贪心，我们每次把操作1操作在最小的元素上，然后把操作2操作在最大的c2个元素上
这样可以保证操作之后的总和是最小的，因此每次二分我们枚举要操作2要操作多少个元素即可
细节较多，代码实现需要技巧
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
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> g(n+1);
	rep(i,1,n+1){
		cin>>g[i];
	}
	sort(all(g));
	rep(i,1,n+1){
		g[i]+=g[i-1];
	}
	if(g[n]<=k){
		cout<<0<<'\n';
		return;
	}
	ll l=0,r=g[n]-k;
	auto check=[&](ll m){
		for(ll i=max(0LL,m-n+1);i<=m;i++){
			ll j=m-i;
			ll res=g[n]-((g[n]-g[n-j])-j*(g[1]-i))-i;
			if(res<=k) return 1;
		}
		return 0;
	};
	while(l<r){
		ll m=(l+r)>>1;
		if(check(m)) r=m;
		else l=m+1;
	}
	cout<<l<<'\n';
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
