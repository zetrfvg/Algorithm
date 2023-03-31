/*
fa[i][j]：i向上走2^j步的祖先
dep[i]：i的深度
d[i]：i到根结点的距离

不妨设结点1为根
对于询问x与y之间的最短距离，可以转换为d[x]+d[y]-2*d[lca(x,y)]
于是转换成了求LCA的问题
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=20010;
vector<vector<int>> fa(N,vector<int>(15));
vector<vector<pair<int,int>>> e(N);
vector<int> dep(N),d(N);

void dfs(int x,int father){
	dep[x]=dep[father]+1;
	fa[x][0]=father;
	for(int i=1;i<=15;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(auto &[y,w]:e[x]){
		if(y!=father){
			d[y]=d[x]+w;
			dfs(y,x);
		}
	}
}

int lca(int x,int y){
	if(dep[y]>dep[x]) swap(x,y);
	for(int i=15;~i;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=15;~i;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i],y=fa[y][i];
		}
	}
	return fa[x][0];
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,root;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int a,b,k;
		cin>>a>>b>>k;
		e[a].push_back({b,k});
		e[b].push_back({a,k});
	}
	dfs(1,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		int l=lca(x,y);
		cout<<d[x]+d[y]-2*d[l]<<'\n';
	}
  	return 0;
}
