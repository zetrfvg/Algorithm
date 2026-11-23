#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps=1e-5;

void solve(){
	int n,p;
	cin>>n>>p;
	vector<pair<int,int>> a(n);
	ll sum=0;
	for(auto &[x,y]:a){
		cin>>x>>y;
		sum+=x;
	}
	if(sum<=p){
		cout<<-1;
		return;
	}
	auto check=[&](double m){
		double res=0;
		for(auto [x,y]:a){
			double self=1.0*y/x;
			if(self>=m) continue;
			res+=m*x-y;
		}
		return res<=m*p+1e-12;
	};
	double l=0,r=1e14;
	for(int i=0;i<100;i++){
		double m=(l+r)/2;
		if(check(m)) l=m;
		else r=m;
	}
	cout<<fixed<<setprecision(10)<<l<<'\n';
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
