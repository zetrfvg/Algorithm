#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,h;
	cin>>n>>m>>h;
	vector<int> horse(n);
	for(int i=0;i<h;i++){
		int x;
		cin>>x;
		horse[x-1]=1;
	}
	vector<vector<pair<int,int>>> e(n);
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		e[x].push_back({y,w});
		e[y].push_back({x,w});
	}
	vector<vector<ll>> ds(n,vector<ll>(2,1e16)),dt(n,vector<ll>(2,1e16));
	auto dijkstra=[&](int st,vector<vector<ll>>& d){
		priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>>> q;
		d[st][0]=0;
		q.push({0,st,0});
		while(!q.empty()){
			auto [dis,x,u]=q.top();
			q.pop();
			if(dis>d[x][u]) continue;
			if(!u&&horse[x]){
				if(d[x][1]>dis){
					d[x][1]=dis;
					q.push({dis,x,1});
					continue;
				}
			}
			for(auto [y,w]:e[x]){
				ll cost=u?w/2:w;
				if(dis+cost<d[y][u]){
					d[y][u]=dis+cost;
					q.push({dis+cost,y,u});
				}
			}
		}
	};
	dijkstra(0,ds);
	dijkstra(n-1,dt);
	ll ans=1e16;
	for(int i=0;i<n;i++){
		ans=min({ans,max(ds[i][0],dt[i][0]),max(ds[i][0],dt[i][1]),max(ds[i][1],dt[i][0]),max(ds[i][1],dt[i][1])});
	}
	cout<<(ans==1e16?-1:ans)<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
