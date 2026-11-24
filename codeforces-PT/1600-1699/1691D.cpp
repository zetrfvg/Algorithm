#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
ll mx[N<<2],mn[N<<2];
ll sum[N],a[N];

void build(int u,int l,int r){
	if(l==r){
		mx[u]=mn[u]=sum[l];
		return;
	}
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
	mx[u]=max(mx[u<<1],mx[u<<1|1]);
	mn[u]=min(mn[u<<1],mn[u<<1|1]);	
}

ll query_mn(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return mn[u];
	}
	int m=(l+r)>>1;
	ll res=1e16;
	if(ql<=m) res=min(res,query_mn(u<<1,l,m,ql,qr));
	if(qr>m) res=min(res,query_mn(u<<1|1,m+1,r,ql,qr));
	return res;
}

ll query_mx(int u,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return mx[u];
	}
	int m=(l+r)>>1;
	ll res=-1e16;
	if(ql<=m) res=max(res,query_mx(u<<1,l,m,ql,qr));
	if(qr>m) res=max(res,query_mx(u<<1|1,m+1,r,ql,qr));
	return res;
}

void clear(int u,int l,int r){
	if(l==r){
		sum[l]=0;
		return;
	}
	mx[u]=mn[u]=0;
	int m=(l+r)>>1;
	clear(u<<1,l,m);
	clear(u<<1|1,m+1,r);
}

void solve(){
	int n;
	cin>>n;
	vector<int> L(n+2,0),R(n+2,n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	stack<int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
		if(!st.empty()) L[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i;i--){
		while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
		if(!st.empty()) R[i]=st.top();
		st.push(i);
	}
	build(1,0,n);
	bool ok=1;
	for(int i=1;i<=n;i++){
		if(query_mx(1,0,n,i,R[i]-1)-query_mn(1,0,n,L[i],i-1)>a[i]){
			ok=0;
			break;
		}
	}
	cout<<(ok?"YES":"NO")<<'\n';
	clear(1,0,n);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
