#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	ll s;
	cin>>n>>s;
	vector<pair<ll,ll>> internals(n);
	for(auto &[l,r]:internals) cin>>l>>r;
	int ans=0;
	auto check=[&](int m){
		int cnt=0;
		ll sum=0;
		vector<int> t;
		for(auto [l,r]:internals){
			if(l>=m){
				sum+=l;
				cnt++;
			}else if(r<m){
				sum+=l;
			}else{
				t.push_back(l);
			}
		}
		if(cnt+t.size()<(n+1)/2) return false;
		sort(t.begin(),t.end(),greater<>());
		int rem=(n+1)/2-cnt;
		for(int i=rem;i<t.size();i++) sum+=t[i];
		sum+=1LL*rem*m;
		return sum<=s;
	};
	int l=1,r=1e9;
	while(l<r){
		int m=(l+r+1)>>1;
		if(check(m)) l=m;
		else r=m-1;
	}
	cout<<l<<'\n';
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
