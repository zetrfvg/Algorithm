#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int tr[1<<20];
int a[1<<18];

void pushup(int u,int l,int r){
	int len=31-__builtin_clz(r-l+1);
	if(len&1){
		tr[u]=tr[u<<1]|tr[u<<1|1];
	}else{
		tr[u]=tr[u<<1]^tr[u<<1|1];
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
	pushup(u,l,r);
}

void modify(int u,int l,int r,int pos,int val){
	if(l==r){
		tr[u]=val;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m) modify(u<<1,l,m,pos,val);
	else modify(u<<1|1,m+1,r,pos,val);
	pushup(u,l,r);
}

void solve(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=(1<<n);i++) cin>>a[i];
	build(1,1,1<<n);
	while(q--){
		int pos,val;
		cin>>pos>>val;
		modify(1,1,1<<n,pos,val);
		cout<<tr[1]<<'\n';
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
