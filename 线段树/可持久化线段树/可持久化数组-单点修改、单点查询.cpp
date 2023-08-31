#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
struct node{
	int l,r;
	int ls,rs,w;
}tr[N<<5];
int rt[N],a[N];
int idx,id;

inline int read(){
    int f=1,x=0;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
    do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
    return f*x;
}

int build(int l,int r){
	int root=++idx;
	tr[root]={l,r,0,0,a[l]};
	if(l==r) return root;
	int m=(l+r)>>1;
	tr[root].ls=build(l,m);
	tr[root].rs=build(m+1,r);
	return root;
}

int modify(int ids,int k,int root){
	int cur=++idx;
	tr[cur]=tr[root];
	if(tr[cur].l==tr[cur].r){
		tr[cur].w=k;
		return cur;
	}
	int m=(tr[cur].l+tr[cur].r)>>1;
	if(ids<=m) tr[cur].ls=modify(ids,k,tr[root].ls);
	else tr[cur].rs=modify(ids,k,tr[root].rs);
	return cur;
}

int query(int ids,int u){
	if(tr[u].l==tr[u].r) return tr[u].w;
	int m=(tr[u].l+tr[u].r)>>1;
	if(ids<=m) return query(ids,tr[u].ls);
	else return query(ids,tr[u].rs);
}

int main(){
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	rt[id++]=build(1,n);
	while(m--){
		int v,op,ids,k;
		v=read(),op=read(),ids=read();
		if(op==1){
			k=read();
			rt[id++]=modify(ids,k,rt[v]);
		}else{
			printf("%d\n",query(ids,rt[v]));
			rt[id++]=rt[v];
		}
	}
  	return 0;
}
