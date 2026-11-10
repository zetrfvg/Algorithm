#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int l=0,r=0;r<n;r++){
		while(a[r]<r-l+1) l++;
		ans+=1LL*(r-l+1);
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
