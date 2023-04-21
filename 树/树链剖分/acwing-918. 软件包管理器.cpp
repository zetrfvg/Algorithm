/*
重链剖分
删除软件：影响的是子树中有已安装软件的个数
安装软件：影响的是从当前节点到根结点的路径上未安装的软件的个数
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10,M=N*2;
int n,q;
int e[M],ne[M],h[N],idx;
int dep[N],sz[N],fa[N],son[N];
int id[N],top[N],cnt;
struct node{
	int l,r;
	int sum,tag;
}tr[N*4];

void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs1(int x,int depth){
	sz[x]=1,dep[x]=depth;
	for(int i=h[x];~i;i=ne[i]){
		int y=e[i];
		dfs1(y,depth+1);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]]) son[x]=y;
	}
}

void dfs2(int x,int t){
	id[x]=++cnt,top[x]=t;
	if(!son[x]) return;
	dfs2(son[x],t);
	for(int i=h[x];~i;i=ne[i]){
		int y=e[i];
		if(y==son[x]) continue;
		dfs2(y,y);
	}
}

void pushup(int u){
	tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushdown(int u){
	if(tr[u].tag){
		auto &rt=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
		if(rt.tag==1){
			l.sum=l.r-l.l+1;
			r.sum=r.r-r.l+1;
		}else{
			l.sum=r.sum=0;
		}
		l.tag=r.tag=rt.tag;
		rt.tag=0;
	}
}

void build(int u,int l,int r){
	tr[u]={l,r,0,0};
	if(l==r) return;
	int m=(l+r)>>1;
	build(u<<1,l,m);
	build(u<<1|1,m+1,r);
}

void modify(int u,int l,int r,int op){
	if(l<=tr[u].l&&tr[u].r<=r){
		if(op==1){
			tr[u].sum=tr[u].r-tr[u].l+1;
			tr[u].tag=1;
		}else{
			tr[u].sum=0;
			tr[u].tag=2;
		}
		return;
	}
	pushdown(u);
	int m=(tr[u].r+tr[u].l)>>1;
	if(l<=m) modify(u<<1,l,r,op);
	if(r>m) modify(u<<1|1,l,r,op);
	pushup(u);
}

int query(int u,int l,int r){
	if(l<=tr[u].l&&tr[u].r<=r){
		return tr[u].sum;
	}
	pushdown(u);
	int res=0;
	int m=(tr[u].l+tr[u].r)>>1;
	if(l<=m) res+=query(u<<1,l,r);
	if(r>m) res+=query(u<<1|1,l,r);
	return res;
}

int install(int x){
	int res=0;
	while(x){
		res+=(id[x]-id[top[x]]+1)-query(1,id[top[x]],id[x]);
		modify(1,id[top[x]],id[x],1);
		x=fa[top[x]];
	}
	return res;
}

int uninstall(int x){
	int res=query(1,id[x],id[x]+sz[x]-1);
	modify(1,id[x],id[x]+sz[x]-1,2);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	memset(h,-1,sizeof h);
	for(int i=2;i<=n;i++){
		int pa;
		cin>>pa;
		pa++;
		add(pa,i);
		fa[i]=pa;
	}
	fa[1]=0;
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--){
		string s;
		int x;
		cin>>s>>x;
		x++;
		if(s=="install"){
			cout<<install(x)<<'\n';
		}else{
			cout<<uninstall(x)<<'\n';
		}
	}
  	return 0;
}
