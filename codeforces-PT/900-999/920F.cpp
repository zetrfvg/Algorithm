#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e5+10;
const int MAXN=1e6;

int cnt[MAXN+10];
int mx[N<<2],a[N];
ll sum[N<<2];

void pushup(int u){
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	sum[u]=sum[u<<1]+sum[u<<1|1];
}

void build(int u,int l,int r){
	if(l==r){
		mx[u]=sum[u]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int lm,int rm){
	if(mx[u]<=2) return;
	if(l==r){
		mx[u]=sum[u]=cnt[mx[u]];
		return;
	}
	int m=(l+r)>>1;
	if(lm<=m) modify(u<<1,l,m,lm,rm);
	if(rm>m) modify(u<<1|1,m+1,r,lm,rm);
	pushup(u);
}

ll query(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return sum[u];
	}
	int m=(l+r)>>1;
	ll res=0;
	if(ql<=m) res+=query(u<<1,l,m,ql,qr);
	if(qr>m) res+=query(u<<1|1,m+1,r,ql,qr);
	return res;
}

void solve(){
	for(int i=1;i<=MAXN;i++){
		for(int j=i;j<=MAXN;j+=i){
			cnt[j]++;
		}
	}
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--){
		int op,l,r;
		cin>>op>>l>>r;
		if(op&1){
			modify(1,1,n,l,r);
		}else{
			cout<<query(1,1,n,l,r)<<'\n';
		}
	}
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
