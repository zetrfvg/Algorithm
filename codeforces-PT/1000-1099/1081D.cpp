#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct DSU{
	int n;
	vector<T> p,siz;
	DSU(int _n):p(_n+1),siz(_n+1),n(_n){
		iota(p.begin(),p.end(),0);
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

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	DSU<int> dsu(n);
	for(int i=0;i<k;i++){
		int p;
		cin>>p;
		dsu.siz[p-1]=1;
	}
	vector<tuple<int,int,int>> e;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		e.push_back({x,y,w});
	}
	sort(e.begin(),e.end(),[&](const auto &i,const auto &j){
		return get<2>(i)<get<2>(j);
	});
	int ans=0;
	for(auto [x,y,w]:e){
		if(dsu.findd(x)!=dsu.findd(y)){
			dsu.unionn(x,y);
			if(dsu.siz[dsu.findd(x)]==k){
				ans=w;
				break;
			}
		}
	}
	for(int i=0;i<k;i++) cout<<ans<<" ";
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
