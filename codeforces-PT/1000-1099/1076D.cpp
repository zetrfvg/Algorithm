#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<tuple<int,ll,int>>> e(n);
	vector<pair<int,int>> ed;
	for(int i=0;i<m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		e[x].push_back({y,w,i+1});
		e[y].push_back({x,w,i+1});
		ed.push_back({x,y});
	}
	vector<ll> dis(n,1e16);
	vector<int> fa(n);
	dis[0]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0,0});
	while(!q.empty()){
		auto [d,x]=q.top();
		q.pop();
		if(d>dis[x]) continue;
		for(auto [y,w,i]:e[x]){
			if(d+w<dis[y]){
				dis[y]=d+w;
				fa[y]=x;
				q.push({dis[y],y});
			}
		}
	}
	vector<int> ans;
	function<void(int,int&)> dfs=[&](int x,int &cnt){
		if(!cnt) return;
		for(auto [y,w,i]:e[x]){
			if(fa[y]==x){
				ans.push_back(i);
				cnt--;
				dfs(y,cnt);
				if(!cnt) return;
			}
		}
	};
	int cnt=k;
	dfs(0,cnt);
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
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
