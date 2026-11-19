#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]=abs(a[i]);
	}
	sort(a.begin(),a.end());
	ll ans=0;
	// for(int l=0,r=0;r<n;l++){
	// 	while(r<n&&(a[l]<<1)>=a[r]) r++;
	// 	ans+=r-l-1;
	// }
	for(int i=0;i<n;i++){
		int pos=upper_bound(a.begin(),a.end(),a[i]<<1)-a.begin();
		ans+=pos-i-1;
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
