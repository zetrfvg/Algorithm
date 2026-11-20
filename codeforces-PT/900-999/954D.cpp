#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	s--,t--;
	vector<vector<int>> e(n),ed(n,vector<int>(n));
	vector<int> ds(n,1e9),dt(n,1e9);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
		e[y].push_back(x);
		ed[x][y]=ed[y][x]=1;
	}
	auto bfs=[&](int st,vector<int>& dis){
		queue<int> q;
		q.push(st);
		while(!q.empty()){
			auto x=q.front();
			q.pop();
			for(auto y:e[x]){
				if(dis[y]==1e9){
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
		}
	};
	ds[s]=0,dt[t]=0;
	bfs(s,ds);
	bfs(t,dt);
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(ed[i][j]) continue;
			if(ds[i]+dt[j]+1>=ds[t]&&ds[j]+dt[i]+1>=ds[t]) ans++;
		}
	}
	cout<<ans;
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
