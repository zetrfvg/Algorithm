#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	auto check=[&](int mid){
		int pre=0;
		for(int i=0;i<n;i++){
			int x=a[i],y=(a[i]+mid)%m;
			if(y>=x){
				if(y<pre) return false;
				pre=max(pre,x);
			}else{
				if(y<pre) pre=max(pre,x);
			}
		}
		return true;
	};
	int l=0,r=m-1;
	while(l<r){
		int mid=(l+r)>>1;
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
