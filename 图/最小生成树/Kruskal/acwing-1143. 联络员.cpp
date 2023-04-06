/*
先将必选的边加入并查集中
然后在图中有若干个连通块的情况下跑一边Kruskal即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(_n+1),siz(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
		for(int i=0;i<=n;i++) siz[i]=1;
	}
	T findd(T x){
		return p[x]==x?x:p[x]=findd(p[x]);
	}
	void unionn(T x,T y){
		x=findd(x),y=findd(y);
		if(x==y) return;
		if(siz[x]>siz[y]) swap(x,y);
		p[x]=y;
		siz[y]+=siz[x];
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	DSU<int> dsu(n);
	int ans=0;
	vector<vector<int>> e;
	for(int i=0;i<m;i++){
		int p,x,y,w;
		cin>>p>>x>>y>>w;
		x--,y--;
		if(p&1){
			dsu.unionn(x,y);
			ans+=w;
		}else{
			e.push_back({w,x,y});
		}
	}
	sort(e.begin(),e.end());
	for(int i=0;i<e.size();i++){
		int x=dsu.findd(e[i][1]);
		int y=dsu.findd(e[i][2]);
		if(x!=y){
			ans+=e[i][0];
			dsu.unionn(x,y);
		}
	}
	cout<<ans;
  	return 0;
}
