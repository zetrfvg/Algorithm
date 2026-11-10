#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	int ans=0;
	vector<ll> l(n),r(n);
	vector<vector<int>> e(n);
	for(int i=1;i<n;i++){
		int p;
		cin>>p;
		p--;
		e[p].push_back(i);
	}
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}
	function<ll(int)> dfs=[&](int x){
		ll sum=0;
		for(auto y:e[x]){
			sum+=dfs(y);
		}
		if(sum>=l[x]){
			return min(r[x],sum);
		}else{
			ans++;
			return r[x];
		}
	};
	dfs(0);
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
