/*
树上路径修改与查询
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10,M=N*2;

struct node{
	int l,r;
	ll sum,add;
}tr[N*4];
int w[N],h[N],e[M],ne[M],idx;
int id[N],nw[N],top[N];
int dep[N],son[N],fa[N],sz[N];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n;
	memset(h,-1,sizeof h);
	function<void(int,int)> add=[&](int a,int b){
		e[idx]=b,ne[idx]=h[a],h[a]=idx++;
	};
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=0;i<n-1;i++){//建树
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	function<void(int,int,int)> dfs1=[&](int x,int father,int depth){
		dep[x]=depth,fa[x]=father,sz[x]=1;
		for(int i=h[x];~i;i=ne[i]){
			int y=e[i];
			if(y==father) continue;
			dfs1(y,x,depth+1);
			sz[x]+=sz[y];
			if(sz[y]>sz[son[x]]) son[x]=y;//找重儿子
		}
	};
	dfs1(1,0,1);
	function<void(int,int)> dfs2=[&](int x,int t){//按DFS序给各个点赋一个新的编号
		id[x]=++cnt,nw[cnt]=w[x],top[x]=t;//t表该链的链头
		if(!son[x]) return;
		dfs2(son[x],t);//为了修改与查询路径上的点，优先遍历重儿子，保证整个重链的编号是连续的
		for(int i=h[x];~i;i=ne[i]){
			int y=e[i];
			if(y==fa[x]||y==son[x]) continue;
			dfs2(y,y);
		}
	};
	dfs2(1,1);
	function<void(int)> pushup=[&](int u){//以下为线段树模板
		tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;	
	};
	function<void(int)> pushdown=[&](int u){
		auto &rt=tr[u],&l=tr[u<<1],&r=tr[u<<1|1];
		if(rt.add){
			l.add+=rt.add;
			l.sum+=rt.add*(l.r-l.l+1);
			r.add+=rt.add;
			r.sum+=rt.add*(r.r-r.l+1);
			rt.add=0;
		}
	};
	function<void(int,int,int)> build=[&](int u,int l,int r){
		tr[u]={l,r,nw[r],0};
		if(l==r) return;
		int m=(l+r)>>1;
		build(u<<1,l,m);
		build(u<<1|1,m+1,r);
		pushup(u);
	};
	function<void(int,int,int,ll)> modify=[&](int u,int l,int r,ll k){
		if(l<=tr[u].l&&tr[u].r<=r){
			tr[u].add+=k;
			tr[u].sum+=k*(tr[u].r-tr[u].l+1);
			return;
		}
		pushdown(u);
		int m=(tr[u].l+tr[u].r)>>1;
		if(l<=m) modify(u<<1,l,r,k);
		if(r>m) modify(u<<1|1,l,r,k);
		pushup(u);
	};
	function<ll(int,int,int)> query=[&](int u,int l,int r){
		if(l<=tr[u].l&&tr[u].r<=r){
			return tr[u].sum;
		}
		pushdown(u);
		ll res=0;
		int m=(tr[u].l+tr[u].r)>>1;
		if(l<=m) res+=query(u<<1,l,r);
		if(r>m) res+=query(u<<1|1,l,r);
		return res;
	};
	build(1,1,n);
	function<void(int,int,int)> modify_path=[&](int u,int v,int k){//两个点一起向上跳，直到二者到同一个重链上，类似求LCA的过程
		while(top[u]!=top[v]){//二者不在一个链上时
			if(dep[top[u]]<dep[top[v]]) swap(u,v);//优先处理深度更大的链
			modify(1,id[top[u]],id[u],k);//修改这个链上的点权
			u=fa[top[u]];//爬到这个链头的父节点上，即跳到上一层重链上
		}
		if(dep[u]<dep[v]) swap(u,v);//二者在同一个重链上时，还需要修改一次
		modify(1,id[v],id[u],k);
	};
	function<ll(int,int)> query_path=[&](int u,int v){//与modify_path方法类似
		ll res=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			res+=query(1,id[top[u]],id[u]);
			u=fa[top[u]];
		}
		if(dep[u]<dep[v]) swap(u,v);
		res+=query(1,id[v],id[u]);
		return res;
	};
	function<void(int,int)> modify_tree=[&](int u,int k){//修改子树，因为子树内的编号一定是连续的，如根结点编号为id[u]，则子树对应的区间为[id[u],id[u]+sz[u]-1]
		modify(1,id[u],id[u]+sz[u]-1,k);	
	};
	function<ll(int)> query_tree=[&](int u){//与modify_tree方法类似
		return query(1,id[u],id[u]+sz[u]-1);
	};
	cin>>m;
	while(m--){
		int op,u,v,k;
		cin>>op>>u;
		if(op==1){
			cin>>v>>k;
			modify_path(u,v,k);
		}else if(op==2){
			cin>>k;
			modify_tree(u,k);
		}else if(op==3){
			cin>>v;
			cout<<query_path(u,v)<<'\n';
		}else{
			cout<<query_tree(u)<<'\n';
		}
	}
  	return 0;
}
