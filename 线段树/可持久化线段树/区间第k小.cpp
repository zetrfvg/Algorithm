#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+10;
struct node{
	int l,r;
	int ls,rs,sum;
}tr[N<<5];
int rt[N];
int idx;
vector<int> ys;

int findd(int val){//离散化
	return lower_bound(ys.begin(),ys.end(),val)-ys.begin()+1;
}

int build(int l,int r){//建树
	int root=++idx;//动态开点
	tr[root]={l,r,0,0,0};
	if(l==r) return root;
	int m=(l+r)>>1;
	tr[root].ls=build(l,m);
	tr[root].rs=build(m+1,r);
	return root;
}

int modify(int k,int root){
	int cur=++idx;//动态开点
	tr[cur]=tr[root];//先复制原节点
	tr[cur].sum++;//该区间加了一个k值，元素数量+1
	if(tr[cur].l==tr[cur].r) return cur;//递归终止
	int m=(tr[cur].l+tr[cur].r)>>1;
	if(k<=m) tr[cur].ls=modify(k,tr[root].ls);//k值在左子区间
	else tr[cur].rs=modify(k,tr[root].rs);//k值在右子区间
	return cur;
}

int query(int u,int v,int k){
	if(tr[u].l==tr[u].r) return tr[u].l;//递归终止
	int x=tr[tr[v].ls].sum-tr[tr[u].ls].sum;//求出区间[l,r]中，左儿子含有多少个元素
	if(k<=x) return query(tr[u].ls,tr[v].ls,k);//左儿子含有元素大于k个，说明第k小的元素在左儿子中
	else return query(tr[u].rs,tr[v].rs,k-x);//否则在右儿子中找第k-x小的元素
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &c:a) cin>>c;
	ys=a;//离散化
	sort(ys.begin(),ys.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	int sz=ys.size();
	rt[0]=build(1,sz);
	for(int i=0;i<n;i++){
		rt[i+1]=modify(findd(a[i]),rt[i]);
	}
	while(m--){
		int l,r,k;
		cin>>l>>r>>k;
		cout<<ys[query(rt[l-1],rt[r],k)-1]<<'\n';
	}
  	return 0;
}
