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
	vector<vector<int>> e(m);
	int ans=0;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		e[i]={x,y,w};
	}
	sort(e.begin(),e.end(),[](const auto &a,const auto &b){
		return a[2]<b[2];
	});
	for(int i=0;i<m;i++){
		int x=e[i][0],y=e[i][1],w=e[i][2];
		x=dsu.findd(x),y=dsu.findd(y);
		if(x!=y){
			ans=max(ans,w);
			dsu.unionn(x,y);
		}
	}
	cout<<n-1<<" "<<ans;
  	return 0;
}
