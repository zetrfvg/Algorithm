#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	auto check=[&](ll mid){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=min(1LL*m,mid/i);
		}
		return cnt>=k;
	};
	ll l=1,r=n*m;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
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
