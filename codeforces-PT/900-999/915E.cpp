#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=15000000;

int tr[N],ls[N],rs[N],lazy[N];
int idx=1;

int getLeftSon(int u){
	if(!ls[u]){
		ls[u]=++idx;
	}
	return ls[u];
}

int getRightSon(int u){
	if(!rs[u]){
		rs[u]=++idx;
	}
	return rs[u];
}

void pushup(int u){
	tr[u]=tr[ls[u]]+tr[rs[u]];
}

void pushdown(int u,int l,int r){
	int m=(l+r)>>1;
	if(lazy[u]==1){
		lazy[getLeftSon(u)]=1;
		tr[getLeftSon(u)]=m-l+1;
		lazy[getRightSon(u)]=1;
		tr[getRightSon(u)]=r-m;
	}else if(lazy[u]==2){
		lazy[getLeftSon(u)]=2;
		tr[getLeftSon(u)]=0;
		lazy[getRightSon(u)]=2;
		tr[getRightSon(u)]=0;
	}
	lazy[u]=0;
}

void modify(int u,int l,int r,int ql,int qr,int c){
	if(ql<=l&&r<=qr){
		lazy[u]=c;
		tr[u]=c==1?r-l+1:0;
		return;
	}
	pushdown(u,l,r);
	int m=(l+r)>>1;
	if(ql<=m) modify(getLeftSon(u),l,m,ql,qr,c);
	if(qr>m) modify(getRightSon(u),m+1,r,ql,qr,c);
	pushup(u);
}

void solve(){
	int n,q;
	cin>>n>>q;
	while(q--){
		int l,r,c;
		cin>>l>>r>>c;
		modify(1,1,n,l,r,c);
		cout<<n-tr[1]<<'\n';
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
