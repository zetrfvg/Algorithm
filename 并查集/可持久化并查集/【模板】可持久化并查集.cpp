/*
即用可持久化数组将并查集中的fa数组可持久化
因为每次操作最多会连一条边，使用路径压缩会破坏掉历史版本的信息，故这里使用按秩合并来保证复杂度
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
struct node{
	int l,r;
	int ls,rs;
	int fa,dep;
}tr[N*20];
int rt[N<<2];
int idx;

int build(int l,int r){//建立初始的线段树
	int root=++idx;
	tr[root]={l,r,0,0,l,1};
	if(l==r) return root;
	int m=(l+r)>>1;
	tr[root].ls=build(l,m);
	tr[root].rs=build(m+1,r);
	return root;
}

int modify_fa(int son,int fa,int root){//把点son的父亲修改为fa
	int cur=++idx;//动态开点
	tr[cur]=tr[root];//复制上一版本的信息
	if(tr[cur].l==son&&tr[cur].r==son){//找到了点son所在的节点
		tr[cur].fa=fa;//修改父亲为fa
		return cur;
	}
	int m=(tr[cur].l+tr[cur].r)>>1;
	if(son<=m) tr[cur].ls=modify_fa(son,fa,tr[root].ls);//点son在左儿子
	else tr[cur].rs=modify_fa(son,fa,tr[root].rs);//点son在右儿子
	return cur;
}

int modify_dep(int fa,int root){//修改fa所在集合的秩，增量为1
	int cur=++idx;
	tr[cur]=tr[root];
	if(tr[cur].l==fa&&tr[cur].r==fa){//找到了fa所在的节点
		tr[cur].dep++;//秩增加
		return cur;
	}
	int m=(tr[cur].l+tr[cur].r)>>1;
	if(fa<=m) tr[cur].ls=modify_dep(fa,tr[root].ls);//点fa在左儿子
	else tr[cur].rs=modify_dep(fa,tr[root].rs);//点fa在右儿子
	return cur;
}

int query_find(int x,int u){//查找x所在的节点u
	if(tr[u].l==tr[u].r){
		return u;//找到了x所在的节点
	}
	int m=(tr[u].l+tr[u].r)>>1;
	if(x<=m) return query_find(x,tr[u].ls);//x在左儿子
	else return query_find(x,tr[u].rs);//x在右儿子
}

int query_fa(int x,int u){//搜索x所在集合的根结点的所在节点
	int v=query_find(x,u);//x所在的节点为v
	if(tr[v].fa==x) return v;//如果x是所在集合的根结点，则直接返回
	else return query_fa(tr[v].fa,u);//否则继续搜索它的父节点
}

int main(){
	int n,m;
	cin>>n>>m;
	rt[0]=build(1,n);//初始化
	for(int i=1;i<=m;i++){
		int op,x,y;
		cin>>op;
		if(op==1){
			cin>>x>>y;
			int u=query_fa(x,rt[i-1]),v=query_fa(y,rt[i-1]);//分别找到x,y的根结点所在的节点u,v
			if(tr[u].fa==tr[v].fa){//二者在同一集合中，无需更改，直接继承上一版本的信息即可
				rt[i]=rt[i-1];
				continue;
			}
			if(tr[u].dep<tr[v].dep) swap(u,v);//令u是秩更大的那个节点
			rt[i]=modify_fa(tr[v].fa,tr[u].fa,rt[i-1]);//把秩更小的集合合并到秩更大的集合中去
			if(tr[u].dep==tr[v].dep) rt[i]=modify_dep(tr[u].fa,rt[i]);//两个集合的秩相同，新的集合秩会变大，修改新集合的秩
		}else if(op==2){
			cin>>x;
			rt[i]=rt[x];//版本回滚
		}else{
			rt[i]=rt[i-1];
			cin>>x>>y;
			x=query_fa(x,rt[i]),y=query_fa(y,rt[i]);分别找到x,y的根结点所在的节点u,v
			if(tr[x].fa==tr[y].fa){//二者是同一个集合
				cout<<1<<'\n';
			}else{//二者不在同一个集合
				cout<<0<<'\n';
			}
		}
	}
  	return 0;
}
