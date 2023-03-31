/*
求x与y的LCA：
设x的深度更大的那个点
首先让x倍增地跳到与y同一层
如果此时x==y，则说明y是x与y的LCA
如果x!=y，则让x与y同时倍增的向上跳，最终跳完之后，它们的父亲结点就是它们的LCA

需要维护fa与dep两个数组，fa的维护与st表的构建类似，求dep则普通dfs即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=40010;
vector<vector<int>> fa(N,vector<int>(16)),e(N);
vector<int> dep(N);

void dfs(int x,int father){
	dep[x]=dep[father]+1;
	fa[x][0]=father;
	for(int i=1;i<=16;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto y:e[x]){
		if(y!=father) dfs(y,x);
	}
}

void lca(int x,int y){
	int res=2;
	if(dep[y]>dep[x]){
		swap(x,y);
		res=1;
	}
	for(int i=16;~i;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y){
		cout<<res<<'\n';
	}else{
		cout<<0<<'\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,root;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(b==-1) root=a;
		else{
			e[a].push_back(b);
			e[b].push_back(a);
		}
	}
	dfs(root,0);
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		lca(x,y);
	}
  	return 0;
}
