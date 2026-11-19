#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=998244353;

ll quickpow(ll a,ll b){
	ll res=1;	
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

void solve(){
	int n,m;
	cin>>n>>m;
	int flag=1;
	vector<int> col(n);
	vector<vector<int>> e(n);
	vector<ll> cnt;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--,y--;
		e[x].push_back(y);
		e[y].push_back(x);
	} 
	auto dfs=[&](auto dfs,int x,int c,int &c1,int &c2)->bool{
		col[x]=c;
		c==1?c1++:c2++;
		for(auto y:e[x]){
			if(!col[y]){
				col[y]=3-c;
				if(!dfs(dfs,y,3-c,c1,c2)) return false;
			}else if(col[x]==col[y]){
				return false;
			}
		}
		return true;
	};
	for(int i=0;i<n;i++){
		if(!col[i]){
			int c1=0,c2=0;
			if(!dfs(dfs,i,1,c1,c2)){
				cout<<0<<'\n';
				return;
			}
			cnt.push_back(quickpow(2,c1)+quickpow(2,c2)%mod);
		}
	}
	ll ans=1;
	for(auto c:cnt){
		ans=ans*c%mod;
	}
	cout<<ans<<'\n';
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
