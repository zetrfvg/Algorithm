/*
对于每一行将所有合法的放置状态枚举出来
状态定义：
dp[i][j]：摆放了前i行，第i行摆放状态为j的方案数量
转移方程：
dp[i][j]=Σdp[i-1][j']
j'为第i-1行的摆放状态，保证与第i行的状态不冲突
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod=1e8;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}
	vector<vector<int>> state(n+1);
	for(int i=0;i<(1<<m);i++){
		if(i&(i>>1)) continue;
		for(int j=1;j<=n;j++){
			bool ok=1;
			for(int d=0;d<m;d++){
				if(!g[j-1][d]&&(i&(1<<d))){
					ok=0;
					break;
				}
			}
			if(ok) state[j].push_back(i);
		}
	}
	ll dp[n+1][(1<<m)];
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	state[0].push_back(0);
	for(int i=1;i<=n;i++){
		for(auto x:state[i]){
			for(auto y:state[i-1]){
				if((x&y)==0){
					dp[i][x]=(dp[i][x]+dp[i-1][y])%mod;
				}
			}
		}
	}
	ll ans=0;
	for(auto y:state.back()){
		ans=(ans+dp[n][y])%mod;
	}
	cout<<ans;
  	return 0;
}
