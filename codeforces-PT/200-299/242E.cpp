#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int B=21;

int tr[N<<2][B];
int lazy[N<<2][B];
int a[N];

void pushup(int u){
	for(int i=0;i<B;i++){
		tr[u][i]=tr[u<<1][i]+tr[u<<1|1][i];
	}
}

void pushdown(int u,int l,int r){
	for(int i=0;i<B;i++){
		if(lazy[u][i]){
			int m=(l+r)>>1;
			tr[u<<1][i]=(m-l+1-tr[u<<1][i]);
			lazy[u<<1][i]^=1;
			tr[u<<1|1][i]=(r-m-tr[u<<1|1][i]);
			lazy[u<<1|1][i]^=1;
			lazy[u][i]=0;
		}
	}
}

void build(int u,int l,int r){
	if(l==r){
		for(int i=0;i<B;i++){
			tr[u][i]=(a[l]>>i)&1;
		}
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int lm,int lr,int x){
	if(lm<=l&&r<=lr){
		for(int i=0;i<B;i++){
			if((x>>i)&1){
				tr[u][i]=(r-l+1)-tr[u][i];
				lazy[u][i]^=1;
			}
		}
		return;
	}
	pushdown(u,l,r);
	int m=(l+r)>>1;
	if(lm<=m) modify(u<<1,l,m,lm,lr,x);
	if(lr>m) modify(u<<1|1,m+1,r,lm,lr,x);
	pushup(u);
}

ll query(int u,int l,int r,int lm,int lr){
	ll res=0;
	if(lm<=l&&r<=lr){
		for(int i=0;i<B;i++){
			res+=(1LL<<i)*tr[u][i];
		}
		return res;
	}
	pushdown(u,l,r);
	int m=(l+r)>>1;
	if(lm<=m) res+=query(u<<1,l,m,lm,lr);
	if(lr>m) res+=query(u<<1|1,m+1,r,lm,lr);
	return res;
}

void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	int m;
	cin>>m;
	while(m--){
		int op,l,r,x;
		cin>>op;
		if(op&1){
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<'\n';
		}else{
			cin>>l>>r>>x;
			modify(1,1,n,l,r,x);
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
