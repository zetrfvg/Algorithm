#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	vector<ll> s;
	DSU(int _n):p(_n+1),siz(_n+1),s(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
		for(int i=0;i<=n;i++) siz[i]=1;
	}
	void init(vector<int>& a){
		for(int i=1;i<a.size();i++) s[i]=a[i];
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
		s[y]+=s[x];
	}
};

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),p(n+1),f(n+2);
	ll cur=0;
	vector<ll> ans(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>p[i];
	DSU<int> dsu(n);
	dsu.init(a);
	for(int i=n;i;i--){
		f[p[i]]=1;
		if(f[p[i]-1]) dsu.unionn(p[i],p[i]-1);
		if(f[p[i]+1]) dsu.unionn(p[i],p[i]+1);
		cur=max(cur,dsu.s[dsu.findd(p[i])]);
		ans[i-1]=cur;
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
