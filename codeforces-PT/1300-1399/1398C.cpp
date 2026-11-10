#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int t=0;
	map<int,int> p;
	p[0]=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		t+=s[i]-'0'-1;
		ans+=p[t];
		p[t]++;
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
