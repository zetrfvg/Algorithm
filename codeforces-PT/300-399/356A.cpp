#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e5+10;
int tr[N<<2];

void pushdown(int u){
	if(!tr[u<<1]){
		tr[u<<1]=tr[u];
	}
	if(!tr[u<<1|1]){
		tr[u<<1|1]=tr[u];
	}
}

void modify(int u,int l,int r,int lm,int rm,int x){
	// cout<<l<<" "<<r<<" "<<lm<<" "<<rm<<'\n';
	if(lm<=l&&r<=rm){
		if(!tr[u]) tr[u]=x;
		return;
	}
	pushdown(u);
	int m=(l+r)>>1;
	if(lm<=m) modify(u<<1,l,m,lm,rm,x);
	if(rm>m) modify(u<<1|1,m+1,r,lm,rm,x);
}

int query(int u,int l,int r,int p){
	if(l==r){
		return tr[u];
	}
	pushdown(u);
	int m=(l+r)>>1;
	if(p<=m) return query(u<<1,l,m,p);
	else return query(u<<1|1,m+1,r,p);
}

void solve(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int l,r,x;
		cin>>l>>r>>x;
		if(x>l) modify(1,1,n,l,x-1,x);
		if(x<r) modify(1,1,n,x+1,r,x);
	}
	for(int i=1;i<=n;i++){
		cout<<query(1,1,n,i)<<" ";
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
