#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	int l=*max_element(a.begin(),a.end()),r=*max_element(a.begin(),a.end())+k;
	auto check=[&](int m){
		for(int i=0;i<n;i++){
			ll res=0;
			int ok=0;
			for(int j=i;j<n;j++){
				if(a[j]>=m-j+i){
					ok=1;
					break;
				}
				else res+=(m-j+i)-a[j];
			}
			if(res<=k&&ok) return true;
		}
		return false;
	};
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
