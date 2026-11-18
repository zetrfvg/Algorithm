#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
ll tr[N<<2],lazy[N<<2];
ll a[N];

void pushup(int u){
	tr[u]=min(tr[u<<1],tr[u<<1|1]);
}

void pushdown(int u){
	if(lazy[u]){
		lazy[u<<1]+=lazy[u];
		lazy[u<<1|1]+=lazy[u];
		tr[u<<1]+=lazy[u];
		tr[u<<1|1]+=lazy[u];
		lazy[u]=0;
	}
}

void build(int u,int l,int r){
	if(l==r){
		tr[u]=a[l];
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int lm,int rm,ll val){
	if(lm<=l&&r<=rm){
		lazy[u]+=val;
		tr[u]+=val;
		return;
	}
	pushdown(u);
	int m=(l+r)>>1;
	if(lm<=m) modify(u<<1,l,m,lm,rm,val);
	if(rm>m) modify(u<<1|1,m+1,r,lm,rm,val);
	pushup(u);
}

ll query(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return tr[u];
	}
	pushdown(u);
	int m=(l+r)>>1;
	ll res=1e16;
	if(ql<=m) res=min(res,query(u<<1,l,m,ql,qr));
	if(qr>m) res=min(res,query(u<<1|1,m+1,r,ql,qr));
	pushup(u);
	return res;
}


void solve(){
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--){
		int l,r;
		ll val,x;
		cin>>l>>r;
		l++,r++;
		if(cin.peek()==' '){
			cin>>val;
			if(l<=r){
				modify(1,1,n,l,r,val);
			}else{
				modify(1,1,n,1,r,val);
				modify(1,1,n,l,n,val);
			}
		}else{
			cin.clear();
			if(l<=r){
				cout<<query(1,1,n,l,r)<<'\n';
			}else{
				cout<<min(query(1,1,n,1,r),query(1,1,n,l,n))<<'\n';
			}
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
