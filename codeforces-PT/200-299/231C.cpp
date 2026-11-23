#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<ll> a(n+1),s(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int sum=0,ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int m=(l+r)>>1;
			if(1LL*(i-m+1)*a[i]-(s[i]-s[m-1])>k) l=m+1;
			else r=m;
		}
		if(i-l+1>sum){
			sum=i-l+1;
			ans=a[i];
		}
	}
	cout<<sum<<" "<<ans<<'\n';
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
