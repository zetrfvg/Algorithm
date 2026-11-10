#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end(),greater<>());
	for(int i=1;i<n;i++) a[i]+=a[i-1];
	while(q--){
		int s;
		cin>>s;
		if(s>a.back()){
			cout<<-1<<'\n';
			continue;
		}
		int l=0,r=n-1;
		while(l<r){
			int m=(l+r)>>1;
			if(a[m]<s) l=m+1;
			else r=m;
		}
		cout<<l+1<<'\n';
	}
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
