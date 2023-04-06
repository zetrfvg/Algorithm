/*
将已连好的线加入并查集
基于Kruskal的做法，先合并权值的小的边，这里即合并纵向的边，再合并横向的边
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
	scanf("%d%d",&n,&m);
	DSU<int> dsu(n*m);
	int a,b,c,d;
	while(~scanf("%d%d%d%d",&a,&b,&c,&d)){
		a--,b--,c--,d--;
		int x=a*m+b,y=c*m+d;
		dsu.unionn(x,y);
	}
	int ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m;j++){
			int x=i*m+j,y=x+m;
			if(dsu.findd(x)!=dsu.findd(y)){
				ans++;
				dsu.unionn(x,y);
			}
		}
	}
	for(int j=0;j<m-1;j++){
		for(int i=0;i<n;i++){
			int x=i*m+j,y=x+1;
			if(dsu.findd(x)!=dsu.findd(y)){
				ans+=2;
				dsu.unionn(x,y);
			}
		}
	}
	cout<<ans;
  	return 0;
}
