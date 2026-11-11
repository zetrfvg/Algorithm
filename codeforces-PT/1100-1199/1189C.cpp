#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,q;
	cin>>n;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<(a[r]-a[l-1])/10<<'\n';
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
