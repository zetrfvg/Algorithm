#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod=1e9+7;

void solve(){
	string s;
	cin>>s;
	ll ans=0;
	int pre=0;
	map<int,ll> p;
	p[0]=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') pre++;
		else pre--;
		ans=(ans+p[pre]*(1LL*s.size()-i))%mod;
		p[pre]+=(p[pre]+i+2)%mod;
	}
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
