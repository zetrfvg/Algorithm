/*
完全背包求方案数
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<ll> g(n),dp(m+1);
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){
			if(j>=g[i]) dp[j]+=dp[j-g[i]];
		}
	}
	cout<<dp[m];
  	return 0;
}
