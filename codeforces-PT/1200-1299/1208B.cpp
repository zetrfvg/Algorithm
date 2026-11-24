#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	map<int,int> p;
	int cnt=0;
	for(auto &x:a){
		cin>>x;
		p[x]++;
	}
	for(auto [x,y]:p){
		if(y==1) cnt++;
	}
	if(cnt==n){
		cout<<0;
		return;
	}
	auto check=[&](int m){
		auto t=p;
		int c=cnt;
		for(int i=0;i<n;i++){
			if(t[a[i]]==1) c--;
			else if(t[a[i]]==2) c++;
			t[a[i]]--;
			if(i>=m-1){
				if(c==n-m) return true;
				if(t[a[i-m+1]]==1) c--;
				else if(t[a[i-m+1]]==0) c++;
				t[a[i-m+1]]++;
			}
		}
		return false;
	};
	int l=0,r=n;
	while(l<r){
		int m=(l+r)>>1;
		if(check(m)) r=m;
		else l=m+1;
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
