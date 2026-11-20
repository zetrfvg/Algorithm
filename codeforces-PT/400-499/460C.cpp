#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,m,w;
	cin>>n>>m>>w;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int l=*min_element(a.begin(),a.end()),r=*max_element(a.begin(),a.end())+m;
	auto check=[&](int mid){
		vector<int> d(n+1);
		ll cur=0,sum=0;
		for(int i=0;i<n;i++){
			cur+=d[i];
			if(a[i]+cur<mid){
				ll cnt=mid-a[i]-cur;
				sum+=cnt;
				d[min(n,i+w)]-=cnt;
				cur+=cnt;
			}
		}
	 	return sum<=m;
	};
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
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
