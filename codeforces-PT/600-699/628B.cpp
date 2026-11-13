#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	string s;
	cin>>s;
	ll ans=0;
	for(int i=0;i<s.size();i++){
		if((s[i]-'0')%4==0) ans++;
		if(i&&stoi(s.substr(i-1,2))%4==0) ans+=i;
	}
	cout<<ans<<'\n';
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
