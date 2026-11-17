#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5;

int tr[N<<2];
string s;

void pushup(int u){
	tr[u]=tr[u<<1]|tr[u<<1|1];
}

void build(int u,int l,int r){
	if(l==r){
		tr[u]=1<<(s[l-1]-'a');
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	pushup(u);
}

void modify(int u,int l,int r,int p,char c){
	if(l==r){
		tr[u]=1<<(c-'a');
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) modify(u<<1,l,m,p,c);
	if(p>m) modify(u<<1|1,m+1,r,p,c);
	pushup(u);
}

int query(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return tr[u];
	}
	int m=(l+r)>>1;
	int res=0;
	if(ql<=m) res|=query(u<<1,l,m,ql,qr);
	if(qr>m) res|=query(u<<1|1,m+1,r,ql,qr);
	return res;
}

void solve(){
	cin>>s;
	int n=s.size();
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int op,l,r;
		char c;
		cin>>op;
		if(op&1){
			cin>>l>>c;
			modify(1,1,n,l,c);
		}else{
			cin>>l>>r;
			cout<<__builtin_popcount(query(1,1,n,l,r))<<'\n';
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
