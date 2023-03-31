/*
并查集+离线来求LCA
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=10010;
vector<vector<pair<int,int>>> e(N),q(N);
vector<int> vis(N),d(N),p(N),ans(N*2);

int find(int x){
	return p[x]==x?x:p[x]=find(p[x]);
}

void dfs(int x,int fa){
	for(auto &[y,w]:e[x]){
		if(y!=fa){
			d[y]=d[x]+w;
			dfs(y,x);
		}
	}
}

void tarjan(int x,int fa){
	for(auto &[y,w]:e[x]){
		if(y!=fa){
			tarjan(y,x);
			p[y]=x;
		}
	}
	for(auto &[y,i]:q[x]){
		if(vis[y]){
			ans[i]=d[x]+d[y]-d[find(y)]*2;
		}
	}
	vis[x]=1;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y,k;
		cin>>x>>y>>k;
		e[x].push_back({y,k});
		e[y].push_back({x,k});
	}
	dfs(1,0);
	iota(p.begin(),p.end(),0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		q[x].push_back({y,i});
		q[y].push_back({x,i});
	}
	tarjan(1,0);
	for(int i=0;i<m;i++){
		cout<<ans[i]<<'\n';
	}
  	return 0;
}
