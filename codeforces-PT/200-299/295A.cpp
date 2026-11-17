#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int tr[N<<2];
int lazy[N<<2];

ll a[N],b[N];
ll l[N],r[N],d[N];

void pushdown(int u){
	if(lazy[u]){
		tr[u<<1]+=lazy[u];
		lazy[u<<1]+=lazy[u];
		tr[u<<1|1]+=lazy[u];
		lazy[u<<1|1]+=lazy[u];
		lazy[u]=0;
	}
}

void modify(int u,int l,int r,int lm,int rm){
	if(lm<=l&&r<=rm){
		tr[u]++;
		lazy[u]++;
		return;
	}
	int m=(l+r)>>1;
	pushdown(u);
	if(lm<=m) modify(u<<1,l,m,lm,rm);
	if(rm>m) modify(u<<1|1,m+1,r,lm,rm);
}

int query(int u,int l,int r,int p){
	if(l==r){
		return tr[u];
	}
	int m=(l+r)>>1;
	pushdown(u);
	if(p<=m) return query(u<<1,l,m,p);
	else return query(u<<1|1,m+1,r,p);
}


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>l[i]>>r[i]>>d[i];
	while(k--){
		int lm,rm;
		cin>>lm>>rm;
		modify(1,1,m,lm,rm);
	}
	for(int i=1;i<=m;i++){
		ll val=d[i]*query(1,1,m,i);
		b[l[i]]+=val;
		b[r[i]+1]-=val;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		cout<<a[i]+b[i]<<" ";
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
