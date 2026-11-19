#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,k,s;
	cin>>n>>m>>k>>s;
	vector<vector<int>> g(k);
	vector<vector<int>> e(n),d(n,vector<int>(k,1e9));
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		g[t-1].push_back(i);
		d[i][t-1]=0;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		--x,--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	auto bfs=[&](int p){
		queue<int> q;
		for(auto x:g[p]){
			q.push(x);
		}
		while(!q.empty()){
			auto x=q.front();
			q.pop();
			for(auto y:e[x]){
				if(d[y][p]!=1e9) continue;
				d[y][p]=d[x][p]+1;
				q.push(y);
			}
		}
	};
	for(int i=0;i<k;i++) bfs(i);
	for(int i=0;i<n;i++){
		sort(d[i].begin(),d[i].end());
		ll ans=0;
		for(int j=0;j<s;j++) ans+=d[i][j];
		cout<<ans<<" ";
	}
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
