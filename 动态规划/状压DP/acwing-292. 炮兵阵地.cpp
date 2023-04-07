/*
左右相邻放置的炮台距离必须大于2，预处理出这些合法的状态
状态定义：
dp[i][j][k]：第i行的摆放状态为j，第i-1行摆放状态为k的最多能摆放的炮台数量
转移方程：
dp[i][x][y]=max(dp[i][x][y],dp[i-1][y][z]+__builtin_popcount(x))
空间开销太大，考虑优化
因为第i行的状态只依赖于前一行，因此用滚动数组来做dp的转移更新
于是转移方程为
dp[i&1][x][y]=max(dp[i&1][x][y],dp[(i-1)&1][y][z]+__builtin_popcount(x))
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> g(n+1);
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='H'){
				g[i]+=(1<<j);
			}
		}
	}
	vector<int> state;
	for(int i=0;i<(1<<m);i++){
		if((i&(i>>1))||(i&(i>>2))) continue;
		state.push_back(i);
	}
	int dp[2][1<<m][1<<m];
	memset(dp,0,sizeof dp);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int x:state){
			for(int y:state){
				for(int z:state){
					if((x&y)||(y&z)||(x&z)) continue;
					if((g[i]&x)||(g[i-1]&y)) continue;
					dp[i&1][x][y]=max(dp[i&1][x][y],dp[(i-1)&1][y][z]+__builtin_popcount(x));
				}
			ans=max(ans,dp[i&1][x][y]);
			}
		}
	}
	cout<<ans;
  	return 0;
}
