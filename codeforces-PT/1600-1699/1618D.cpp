#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0;
	sort(a.begin(),a.end(),greater<>());
	for(int i=0;i<k;i++){
		ans+=a[i+k]/a[i];
	}
	for(int i=2*k;i<n;i++) ans+=a[i];
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
