#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int mx[N<<2];
ll sum[N<<2];
int a[N];

void pushup(int u){
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	sum[u]=sum[u<<1]+sum[u<<1|1];
}

void build(int u,int l,int r){
	if(l==r){
		sum[u]=mx[u]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	pushup(u);
}

void modify_mod(int u,int l,int r,int lm,int rm,int mod){
	if(mx[u]<mod) return;
	if(l==r){
		mx[u]%=mod;
		sum[u]%=mod;
		return;
	}
	int m=(l+r)>>1;
	if(lm<=m) modify_mod(u<<1,l,m,lm,rm,mod);
	if(rm>m) modify_mod(u<<1|1,m+1,r,lm,rm,mod);
	pushup(u);
}

void modify_val(int u,int l,int r,int p,int val){
	if(l==r){
		mx[u]=sum[u]=val;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) modify_val(u<<1,l,m,p,val);
	else modify_val(u<<1|1,m+1,r,p,val);
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
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	while(m--){
		int op,l,r,x;
		cin>>op;
		if(op==1){
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<'\n';
		}else if(op==2){
			cin>>l>>r>>x;
			modify_mod(1,1,n,l,r,x);
		}else{
			cin>>l>>x;
			modify_val(1,1,n,l,x);
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
