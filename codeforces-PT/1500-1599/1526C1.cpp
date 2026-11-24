#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	ll cur=0;
	int ans=0;
	for(auto x:a){
		cur+=x;
		q.push(x);
		ans++;
		if(cur<0){
			cur-=q.top();
			q.pop();
			ans--;
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
