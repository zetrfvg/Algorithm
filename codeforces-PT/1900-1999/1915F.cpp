#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct Fenwick{
	int n;
	vector<T> tr;
	Fenwick(){}
	Fenwick(int _n):tr(_n+1),n(_n){
		for(int i=0;i<=n;i++) tr[i]=0;
	}
	T lowbit(T x){
		return x&-x;
	}
	void add(int u,T x){
		for(int i=u;i<=n;i+=lowbit(i)) tr[i]+=x;
	}
	T query(int u){
		T res=0;
		for(int i=u;i;i-=lowbit(i)) res+=tr[i];
		return res;
	}
};

void solve(){
	int n;
	cin>>n;
	vector<pair<int,int>> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		mp[a[i].second]=1;
	}
	int idx=0;
	sort(a.begin(),a.end());
	for(auto &x:mp){
		x.second=++idx;
	}
	Fenwick<int> fen(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=1LL*(fen.query(n)-fen.query(mp[a[i].second]-1));
		fen.add(mp[a[i].second],1);
	}
	cout<<ans<<'\n';
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
