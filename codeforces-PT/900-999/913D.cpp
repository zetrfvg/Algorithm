#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,t;
	cin>>n>>t;
	vector<pair<int,int>> a(n);
	vector<int> idx(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		idx[i]=i;
	}
	sort(idx.begin(),idx.end(),[&](const auto i,const auto j){
		return a[i].second<a[j].second;
	});
	int l=0,r=n;
	auto check=[&](int m){
		int res=0,sum=t;
		for(auto &i:idx){
			if(a[i].first>=m&&sum>=a[i].second){
				res++;
				sum-=a[i].second;
			}
		}
		return res>=m;
	};
	while(l<r){
		int m=(l+r+1)>>1;
		if(check(m)) l=m;
		else r=m-1;
	}
	cout<<l<<'\n'<<l<<'\n';
	for(int i=0,j=l;j;i++){
		if(a[idx[i]].first>=l){
			cout<<idx[i]+1<<" ";
			j--;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
