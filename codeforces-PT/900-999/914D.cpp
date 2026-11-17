#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;

int tr[N<<2];
int a[N];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void pushup(int u){
	tr[u]=gcd(tr[u<<1],tr[u<<1|1]);
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

void modify(int u,int l,int r,int p,int x){
	if(l==r){
		tr[u]=x;
		return;
	}
	int m=(l+r)>>1;
	if(p<=m) modify(u<<1,l,m,p,x);
	else modify(u<<1|1,m+1,r,p,x);
	pushup(u);
}

int query(int u,int l,int r,int ql,int qr,int x){
	int res=0;
	if(ql<=l&&r<=qr){
		if(tr[u]%x==0) return 0;
		else if(l==r) return 1;
	}
	int m=(l+r)>>1;
	if(ql<=m) res+=query(u<<1,l,m,ql,qr,x);
	if(res>1) return res;
	if(qr>m) res+=query(u<<1|1,m+1,r,ql,qr,x);
	return res;
}

void solve(){
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	cin>>q;
	while(q--){
		int op,l,r,x;
		cin>>op;
		if(op&1){
			cin>>l>>r>>x;
			if(query(1,1,n,l,r,x)<2){
				cout<<"YES"<<'\n';
			}else{
				cout<<"NO"<<'\n';
			}
		}else{
			cin>>l>>x;
			modify(1,1,n,l,x);
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
