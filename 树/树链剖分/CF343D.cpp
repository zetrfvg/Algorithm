/*
树链剖分+区间覆盖的线段树
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10,M=N*2;
int h[N],e[M],ne[M],idx;
int L[N],R[N],top[N],cnt;
int dep[N],fa[N],sz[N],son[N];
struct node{
	int l,r,v,tag;
}tr[N*4];

void add(int a,int b){
	e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}

void dfs1(int x,int father,int depth){
	dep[x]=depth,fa[x]=father,sz[x]=1;
	for(int i=h[x];i;i=ne[i]){
		int y=e[i];
		if(y==father) continue;
		dfs1(y,x,depth+1);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
}

void dfs2(int x,int t){
	L[x]=R[x]=++cnt,top[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=h[x];i;i=ne[i]){
		int y=e[i];
		if(y==fa[x]||y==son[x]) continue;
		dfs2(y,y);
	}
	R[x]=cnt;
}

void build(int u,int l,int r){
	tr[u]={l,r,0,-1};
	if(l==r) return;
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
}

void pushdown(int u){
	if(tr[u].tag!=-1){
		tr[u<<1].v=tr[u<<1|1].v=tr[u].v;
		tr[u<<1].tag=tr[u<<1|1].tag=tr[u].tag;
		tr[u].tag=-1;
	}
}

void modify(int u,int l,int r,int k){
	if(l<=tr[u].l&&tr[u].r<=r){
		tr[u].v=k;
		tr[u].tag=k;
		return;
	}
	pushdown(u);
	int m=(tr[u].l+tr[u].r)>>1;
	if(l<=m) modify(u<<1,l,r,k);
	if(r>m) modify(u<<1|1,l,r,k);
}

int query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r){
		return tr[u].v;
	}
	pushdown(u);
	int m=(tr[u].l+tr[u].r)>>1;
	int res=0;
	if(l<=m) res+=query(u<<1,l,r);
	if(r>m) res+=query(u<<1|1,l,r);
	return res;
}

void modify_subtree(int x){
	modify(1,L[x],R[x],1);
}

void modify_to_root(int x){
	while(top[x]){
		modify(1,L[top[x]],L[x],0);
		x=fa[top[x]];
	}
}

int query_value(int x){
	return query(1,L[x],L[x]);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
	}
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n);
	int q;
	cin>>q;
	while(q--){
		int op,x;
		cin>>op>>x;
		if(op==1){
			modify_subtree(x);
		}else if(op==2){
			modify_to_root(x);
		}else{
			cout<<query_value(x)<<'\n';
		}
	}
  	return 0;
}
