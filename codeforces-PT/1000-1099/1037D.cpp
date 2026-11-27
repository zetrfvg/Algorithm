#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<vector<int>> e(n);
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	vector<int> p(n);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		p[x-1]=i;
	}
	for(auto &t:e){
		sort(t.begin(),t.end(),[&](const auto &x,const auto &y){
			return p[x]<p[y];
		});
	}
	vector<int> vis(n);
	queue<int> q;
	q.push(0);
	vis[0]=1;
	vector<int> res(n);
	int idx=0;
	while(!q.empty()){
		auto x=q.front();
		q.pop();
		for(auto y:e[x]){
			if(vis[y]) continue;
			vis[y]=1;
			q.push(y);
			res[y]=++idx;
		}
	}
	cout<<(res==p?"YES":"NO")<<'\n';
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
