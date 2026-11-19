#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> col(n);
	vector<vector<int>> e(n);
	vector<pair<int,int>> ed;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
		e[y].push_back(x);
		ed.push_back({x,y});
	}
	auto dfs=[&](auto dfs,int x,int c)->bool{
		for(auto y:e[x]){
			if(!col[y]){
				col[y]=3-c;
				if(!dfs(dfs,y,3-c)) return false;
			}else if(col[y]==col[x]){
				return false;
			}else{
				continue;
			}
		}
		return true;
	};
	col[0]=1;
	if(!dfs(dfs,0,1)){
		cout<<"NO";
		return;
	}
	cout<<"YES";
	for(auto [x,y]:ed){
		cout<<(col[x]==2?0:1);
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
