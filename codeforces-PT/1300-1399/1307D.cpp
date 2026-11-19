#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> spe;
	vector<vector<int>> e(n);
	vector<int> ds(n,1e9),dt(n,1e9);
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		spe.push_back(x-1);
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	auto bfs=[&](int s,vector<int>& d){
		d[s]=0;
		queue<pair<int,int>> q;
		q.push({0,s});
		while(!q.empty()){
			auto [dis,x]=q.front();
			q.pop();
			for(auto y:e[x]){
				if(d[y]==1e9){
					d[y]=d[x]+1;
					q.push({d[y],y});
				}
			}
		}
	};
	bfs(0,ds);
	bfs(n-1,dt);
	sort(spe.begin(),spe.end(),[&](int i,int j){
		return ds[i]-dt[i]<ds[j]-dt[j];
	});
	int maxds=ds[spe[0]];
	int best=0;
	for(int i=1;i<k;i++){
		best=max(best,maxds+dt[spe[i]]+1);
		maxds=max(maxds,ds[spe[i]]);
	}
	cout<<min(ds[n-1],best)<<'\n';
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
