#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
int tr[N<<2];
struct Node{
	int lazy;
	int x,y,k;
}node[N<<2];
int a[N];
int b[N];

void pushdown(int u){
	if(node[u].lazy){
		node[u<<1]=node[u];
		node[u<<1|1]=node[u];
		node[u]={0,0,0,0};
	}
}

void build(int u,int l,int r){
	tr[u]=b[l];
	if(l==r){
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
}

void modify(int u,int l,int r,int x,int y,int k){
	if(y<=l&&r<=y+k-1){
		node[u]={1,x,y,k};
		tr[u]=a[l-node[u].y+node[u].x];
		return;
	}
	int m=(l+r)>>1;
	pushdown(u);
	if(y<=m) modify(u<<1,l,m,x,y,k);
	if(y+k-1>m) modify(u<<1|1,m+1,r,x,y,k);
}

int query(int u,int l,int r,int p){
	if(l==r){
		if(node[u].lazy){
			return a[node[u].x+p-node[u].y];
		}else{
			return b[p];
		}
	}
	int m=(l+r)>>1;
	pushdown(u);
	if(p<=m) return query(u<<1,l,m,p);
	else return query(u<<1|1,m+1,r,p);
}


void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	while(m--){
		int op,x,y,k;
		cin>>op;
		if(op&1){
			cin>>x>>y>>k;
			modify(1,1,n,x,y,k);
		}else{
			cin>>x;
			cout<<query(1,1,n,x)<<'\n';
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
