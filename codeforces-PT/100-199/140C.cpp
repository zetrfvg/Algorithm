#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	map<int,int> p;
	for(int i=0;i<n;i++){
		int r;
		cin>>r;
		p[r]++;
	}
	priority_queue<pair<int,int>> q;
	for(auto [x,y]:p) q.push({y,x});
	int ans=0;
	vector<tuple<int,int,int>> res;
	while(q.size()>=3){
		vector<pair<int,int>> t(3);
		for(int i=0;i<3;i++){
			t[i]=q.top();
			q.pop();
		}
		for(int i=0;i<3;i++){
			if(--t[i].first){
				q.push(t[i]);
			}
		}
		ans++;
		res.push_back({t[0].second,t[1].second,t[2].second});
	}
	cout<<ans<<'\n';
	for(auto [x,y,z]:res){
		cout<<max({x,y,z})<<" "<<x+y+z-max({x,y,z})-min({x,y,z})<<" "<<min({x,y,z})<<'\n';
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
